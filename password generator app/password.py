import string
from random import randint, choice
from tkinter import *

def generate_password():
    password_min = 6
    password_max = 12
    all_chars = string.ascii_letters + string.punctuation + string.digits

    password = "".join(choice(all_chars) for x in range(randint(password_min, password_max)))
    password_entry.delete(0, END)
    password_entry.insert(0, password)

# creer window
window = Tk()
window.title("password generator")
window.geometry("900x500")
window.iconbitmap("password generator logo.ico")
window.config(background='#8AFAEB')

# creer frame principale
frame = Frame(window, bg='#8AFAEB',)

# creer image
width = 480
height = 359.5
image = PhotoImage(file="password.png.png").zoom(35).subsample(32)
canvas = Canvas(frame, width=width, height=height, bg='#8AFAEB', bd=0, highlightthickness=0)
canvas.create_image(width/2, height/2, image=image)
canvas.grid(row=0, column=0, sticky=W)

# creer une soos boite
right_frame = Frame(frame, bg='#8AFAEB')

# creer titre
label_title = Label(right_frame, text="Enter password please :", font=("halvetica", 20), bg='#8AFAEB', fg='black')
label_title.pack()

# creer champs/entrée/input
password_entry = Entry(right_frame, font=("halvetica", 20), bg='#8AFAEB', fg='black')
password_entry.pack()

# creer un boutton
generate_password_button = Button(right_frame, text="generate !", font=("halvetica", 20), bg='#8AFAEB', fg='black', command=generate_password)
generate_password_button.pack(fill=X)

# placer la sous boite à droite de la frame pricipale
right_frame.grid(row=0, column=1, sticky=W)

# afficher la frame
frame.pack(expand=YES)

# creer une barre de menu
menu_bar = Menu(window)

# creer un 1er menu
file_menu = Menu(menu_bar, tearoff=0)
file_menu.add_command(label="New", command=generate_password)
file_menu.add_command(label="Exit", command=window.quit)
menu_bar.add_cascade(label="File", menu=file_menu)

# configurer fenetre pour ajouter menu bar
window.config(menu=menu_bar)

# afficher window
window.mainloop()