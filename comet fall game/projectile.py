import pygame

# définir la classe qui va gérer le projectile du joueur
class Projectile(pygame.sprite.Sprite):

    # définir la cnstructer de la classe
    def __init__(self, player):
        super().__init__()
        self.velocity = 5
        self.player = player
        self.image = pygame.image.load('assets/spear.png')
        self.image = pygame.transform.scale(self.image, (50, 50))
        self.image = pygame.transform.rotate(self.image, -45)
        self.rect = self.image.get_rect()
        self.rect.x = player.rect.x + 80
        self.rect.y = player.rect.y

    def remove(self):
        self.player.all_projectiles.remove(self)

    def move(self):
        self.rect.x += self.velocity

        # verifier si notre projectile entre en collision avec un monstre
        for monster in self.player.game.check_collision(self, self.player.game.all_monsters):
            # supprimer notre projectile
            self.remove()
            # infliger des dégats
            monster.damage(self.player.attack)



