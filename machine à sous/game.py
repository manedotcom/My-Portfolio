import pygame, numpy
pygame.init()

# crrer une classe qui va gérer les emplacements
class Emplacement(pygame.sprite.Sprite):

    def __init__(self, pos_x, pos_y):
        super().__init__()
        self.image = pygame.image.load('images/pomme_dore.png')
        self.rect = self.image.get_rect()
        self.rect.x = pos_x
        self.rect.y = pos_y

    def set_image(self, image):
        self.image = image

# definir une fonction lancement
def lancement():

    global jetons

    # choix au hasard selon les probabilitées
    random_fruits = numpy.random.choice(fruits, 3, p=proba_fruits)
    fruit_gauche = fruits_dict_image[random_fruits[0]]
    fruit_milieu = fruits_dict_image[random_fruits[1]]
    fruit_droite = fruits_dict_image[random_fruits[2]]

    # changement des images
    emplacement_gauche.set_image(fruit_gauche)
    emplacement_milieu.set_image(fruit_milieu)
    emplacement_droite.set_image(fruit_droite)

    # verification des lots
    if random_fruits[0] == random_fruits[1] == random_fruits[2]:
        jetons_gagnes = fruits_dict_jetons[random_fruits[0]]
        jetons += jetons_gagnes

# creer la fenetre du jeu
largeur = 800
hauteur = 460
pygame.display.set_icon(pygame.image.load('images/pomme_dore.png'))
window = pygame.display.set_mode((largeur, hauteur))
pygame.display.set_caption('Machine à sous')
white = [255] * 3

# argent du joueur
jetons = 500
pay = 10

# dictionnaire des images des fruits
fruits_dict_image = {
    "cerise": pygame.image.load('images/cerise.png'),
    "ananas": pygame.image.load('images/ananas.png'),
    "pasteque": pygame.image.load('images/pasteque.png'),
    "orange": pygame.image.load('images/orange.png'),
    "pomme_dorrée": pygame.image.load('images/pomme_dore.png')
}

# liste des fruits
fruits = ['ananas', 'cerise', 'orange', 'pasteque', 'pomme_dorrée']
proba_fruits = [0.18, 0.23, 0.38, 0.11, 0.1]

# dictionnaire des jetons des fruits
fruits_dict_jetons = {
    "orange": 5,
    "cerise": 15,
    "ananas": 50,
    "pasteque": 150,
    "pomme_dorrée": 10000
}

# chargement des emplacements
hauteur_emplacements = hauteur / 2 + 27
emplacement_x_milieu = largeur / 3 + 62
emplacement_x_droite = largeur / 3 + 162
emplacement_x_gauche =largeur / 3 - 40

emplacements = pygame.sprite.Group()
emplacement_gauche = Emplacement(emplacement_x_gauche, hauteur_emplacements)
emplacement_milieu = Emplacement(emplacement_x_milieu, hauteur_emplacements)
emplacement_droite = Emplacement(emplacement_x_droite, hauteur_emplacements)

# rangement des emplacements dans le group
emplacements.add(emplacement_gauche)
emplacements.add(emplacement_milieu)
emplacements.add(emplacement_droite)

# charger l'image de l'arriere plan
fond = pygame.image.load("images/slot.png")
police_jetons = pygame.font.SysFont("ubuntu", 40)
police_error = pygame.font.SysFont("ubuntu", 40)
police_quit = pygame.font.SysFont("ubuntu", 30)
police_cheat = pygame.font.SysFont("ubuntu", 20)
clock = pygame.time.Clock()

# boucle : pour maintenir la fenetre pygame en eveil
running = True

while running:

    window.fill(white)
    window.blit(fond, (0, 0))

    for event in pygame.event.get():
        # pas assez d'argent
        if jetons < pay:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_a:
                    pygame.quit()
                    quit()
                elif event.key == pygame.K_r:
                    jetons = 500
                    lancement()
        # verifier si le joueur ferme la fenetre
        if event.type == pygame.QUIT:
            running = False
            quit()
        # verifier si le joueur appuie sur une touche
        if event.type == pygame.KEYDOWN:
            # si la touche est la touche ESPACE
            if event.key == pygame.K_SPACE and jetons >= pay:
                lancement()
                jetons -= pay
            elif event.key == pygame.K_F5:
                jetons += 1000
                text_cheat = police_cheat.render("TRICHE ACTIVÈ !", True, (0, 0, 0))
                window.blit(text_cheat, (20, 30))

    if jetons < pay:
        text_error = police_error.render("Vous n'avez pas assez de jetons !", True, (255, 0, 0))
        window.blit(text_error, (largeur / 3 - 123, 177))
        text_quit = police_quit.render("Appuyez sur la touche Q pour quitter ou R pour redémarrer", True, (255, 0, 0))
        window.blit(text_quit, (largeur / 3 - 183, 205))

    # afficher son nombre de jetons
    text_jetons = police_jetons.render(str(jetons) + " jetons", True, (226, 180, 116))
    window.blit(text_jetons, (10, 0))

    emplacements.draw(window)
    pygame.display.flip()