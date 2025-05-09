import pygame, math
from projectile import Projectile
from monster import Monster
pygame.init()

# creer une 2eme classe qui va representer notre jeu
class Game:

    def __init__(self):
        # definir si notre jeu a commencé
        self.is_playing = False

        # generer notre joueur
        self.all_players = pygame.sprite.Group()
        self.player = Player(self)
        self.all_players.add(self.player)
        # groupe de monstres
        self.all_monsters = pygame.sprite.Group()
        self.pressed = {}

    def start(self):
        self.is_playing = True
        self.spawn_monster()
        self.spawn_monster()
        self.spawn_monster()

    def game_over(self):
        self.all_monsters = pygame.sprite.Group()
        self.player.health = self.player.max_health
        self.is_playing = False

    def update(self):

        # appliquer l'image du joueur
        screen.blit(game.player.image, game.player.rect)

        # actualiser la bar de vie du joueur
        health_police = pygame.font.SysFont("alycidon", 22)
        ceil_health = math.ceil(game.player.health)
        health_text = health_police.render(str(ceil_health), True, (53, 135, 234))
        screen.blit(health_text, (game.player.rect.x + 2, game.player.rect.y - 28))
        game.player.update_health_bar(screen)

        # recuperer les projectiles du joueur
        for projectile in game.player.all_projectiles:
            projectile.move()

        # recuperer les monstres du joueur
        for monster in game.all_monsters:
            monster.forwad()
            monster.update_health_bar(screen)

        # appliquer l'ensemble des images de mon groupe de projectiles
        game.player.all_projectiles.draw(screen)

        # appliquer l'ensemble des images de mon groupe de monstres
        game.all_monsters.draw(screen)

        # verifier si le joueur souhaite aller à droite ou à gauche
        if game.pressed.get(pygame.K_d) and game.player.rect.x < 680:
            game.player.move_right()
        elif game.pressed.get(pygame.K_q) and game.player.rect.x > 0:
            game.player.move_left()

    def spawn_monster(self):
        monster = Monster(self)
        self.all_monsters.add(monster)

    def check_collision(self, sprite, group):
        return pygame.sprite.spritecollide(sprite, group, False, pygame.sprite.collide_mask)

# creer une 1ere classe qui va representer notre joueur
class Player(pygame.sprite.Sprite):

    def __init__(self, game):
        super().__init__()
        self.game = game
        self.health = 100
        self.max_health = 100
        self.attack = 10
        self.velocity = 4.5
        self.all_projectiles = pygame.sprite.Group()
        self.image = pygame.image.load('assets/centaur.png')
        self.image = pygame.transform.scale(self.image, (110, 110))
        self.rect = self.image.get_rect()
        self.rect.x = 340
        self.rect.y = 292

    def damage(self, amount):
        if self.health - amount >= amount:
            self.health -= amount
        else:
            # 0 points de vie
            self.game.game_over()

    def update_health_bar(self, surface):
        # dessiner les bars
        pygame.draw.rect(surface, (60, 63, 60), [self.rect.x + 2, self.rect.y - 15, self.max_health, 5])
        pygame.draw.rect(surface, (53, 135, 234), [self.rect.x + 2, self.rect.y - 15, self.health, 5])

    def launch_projectile(self):
        # creer une nouvelle instance de la classe projectile
        self.all_projectiles.add(Projectile(self))

    def move_right(self):
        # si le joueur n'est pas en collision avec un monstre
        if not self.game.check_collision(self, self.game.all_monsters):
             self.rect.x += self.velocity

    def move_left(self):
        self.rect.x -= self.velocity

# generer la fenetre du jeu
pygame.display.set_caption("comet fall game")
screen = pygame.display.set_mode((810, 540))
pygame.display.set_icon(pygame.image.load('assets/centaur.png'))

# importer de changer l'arriere plan du jeu
background = pygame.image.load('assets/forest bg.jpg')

# importer charger la bannière
banner = pygame.image.load('assets/my banner.png')
banner = pygame.transform.scale(banner, (340, 260))

play_police = pygame.font.SysFont("alycidon", 30)

# charger notre jeu
game = Game()

# charger notre joueur
player = Player(game)

running = True

# boucle : tant que cette condition est vraie
while running:

    #appliquer l'arriere plan du jeu
    screen.blit(background, (0, 30))

    # verifier si notre jeu a commencé ou non
    if game.is_playing:
        game.update()
    else:
        # ajouter l'ecran de bienvenue
        #screen.blit(play_button, (305, 255))
        screen.blit(banner, (235, 30))
        play_text = play_police.render("PRESS 'P' TO PLAY OR 'Q' TO QUIT !", True, (255, 255, 255))
        screen.blit(play_text, (230, 300))

    # mattre à jour l'écran
    pygame.display.flip()

    # si le player ferme la fenetre
    for event in pygame.event.get():
        # que l'evenement est fermeture de fenetre
        if event.type == pygame.QUIT:
            running = False
            pygame.quit()
        # detecter si le joueur lache une touche du clavier
        elif event.type == pygame.KEYDOWN:
            game.pressed[event.key] = True

            # detecter si la touce SPACE est enlenchée pour lancer notre projectile
            if event.key == pygame.K_SPACE:
                game.player.launch_projectile()

            if event.key == pygame.K_p and game.is_playing == False:
                game.start()

            elif event.key == pygame.K_a and game.is_playing == False:
                running = False
                pygame.quit()
                quit()

        elif event.type == pygame.KEYUP:
            game.pressed[event.key] = False