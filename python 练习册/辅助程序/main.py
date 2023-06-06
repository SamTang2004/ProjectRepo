import tkinter as tk
from tkinter.ttk import Frame, Button, Entry, Style
from tkinter import Tk, W, E, Text, Label, OptionMenu

def getAircrafts():
    pass

def getMainGuns():
    pass

class Sync(Frame):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.master.title("AL Syncing Tool")
        for i in range(4):
            self.columnconfigure(i, pad = 3)
        for i in range(7):
            self. rowconfigure(i, pad = 3)

        RLDText = Label(self, text = "RLD")
        RLDText.grid(row= 0, column = 0)

        Slot1Text = Label(self, text = "Slot 1")
        Slot1Text.grid(row = 0, column= 1)

        Slot2Text = Label(self, text = "Slot 2")
        Slot2Text.grid(row=0, column = 2)
        
        Slot3Text = Label(self, text = "Slot 3")
        Slot3Text.grid(row=0, column = 3)

        Utility1Text = Label(self, text = "Util 1")
        Utility1Text.grid(row = 0, column = 4)

        Utility2Text = Label(self, text = "Util 2")
        Utility2Text.grid(row = 0, column = 5)

        FinalTimeText = Label(self, text = "Loading time taken")
        FinalTimeText.grid(row = 0, column = 6)

        RLDEntry1 = Entry(self)
        RLDEntry1.grid(row = 1, column = 0)

        RLDEntry2 = Entry(self)
        RLDEntry2.grid(row = 2, column = 0)

        RLDEntry3 = Entry(self)
        RLDEntry3.grid(row = 3, column = 0)
        self.pack(ipadx = 10, ipady = 10)

        dropdownOptions

        

def main():
    root = tk.Tk()
    app = Sync()
    root.mainloop()

if __name__ == "__main__":
    main()
