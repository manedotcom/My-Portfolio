import pygame, random

# creer la class du monstre
class Monster(pygame.sprite.Sprite):

    def __init__(self, game):
        super().__init__()
        self.game = game
        self.health = 80
        self.max_health = 80
        self.attack = 0.3
        self.velocity = random.uniform(0.6, 1.2)
        self.image = pygame.image.load('assets/vampire.png')
        self.image = pygame.transform.scale(self.image, (90, 90))
        self.rect = self.image.get_rect()
        self.rect.x = 700 + random.randint(0, 300)
        self.rect.y = 312

    def damage(self, amount):
        self.health -= amount

        # death
        if self.health <= 0:
            # respawn
            self.rect.x = 810 + random.randint(0, 300)
            self.velocity = random.uniform(0.6, 1.2)
            self.health = self.max_health

    def update_health_bar(self, surface):
        # dessiner les bars
        pygame.draw.rect(surface, (60, 63, 60), [self.rect.x + 2, self.rect.y - 15, self.max_health, 5])
        pygame.draw.rect(surface, (111, 210, 46), [self.rect.x + 2, self.rect.y - 15, self.health, 5])

    def forwad(self):
        # le déplacement ne se fait que si il n'y a pas de collision avec un joueur
        if not self.game.check_collision(self, self.game.all_players):
            self.rect.x -= self.velocity
        # si le monstre est en collision avec le joueur
        else:
            # infliger des dégats au joueur
            self.game.player.damage(self.attack)