from tkinter import *
from tkinter.messagebox import showinfo

def newfile():
    pass
def openfile():
    pass
def savefile():
    pass
def exit():
    root.destroy()
def cut():
    textArea.event_generate(("<<Cut>>"))
def copy():
   textArea.event_generate(("<<Copy>>"))
def paste():
    textArea.event_generate(("<<Paste>>"))
def about():
    showinfo("Notepad ","By Almas Dinani" )


root=Tk()
root.geometry("400x500")
root.title("Untitled - Notepad")


textArea = Text(root, font="lucida 13")
textArea.pack(expand=True, fill=BOTH)


menubar = Menu(root)
filemenu = Menu(menubar, tearoff=0)
filemenu.add_command(label="New", command=newfile)
filemenu.add_command(label="Open", command=openfile)
filemenu.add_command(label="Save", command=savefile)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=exit)
menubar.add_cascade(label="File",menu=filemenu)


editmenu = Menu(menubar,tearoff=0)
editmenu.add_command(label="Cut", command=cut)
editmenu.add_command(label="Copy", command=copy)
editmenu.add_command(label="Paste", command=paste)
menubar.add_cascade(label="Edit" ,menu=editmenu)

helpmenu = Menu(menubar,tearoff=0)
helpmenu.add_command(label="About Notepad",command=about)
menubar.add_cascade(label="Help" ,menu=helpmenu)

root.config(menu=menubar)

Scroll = Scrollbar(textArea)
Scroll.pack(side=RIGHT,  fill=Y)
Scroll.config(command=textArea.yview)
textArea.config(yscrollcommand=Scroll.set)

root.mainloop()
