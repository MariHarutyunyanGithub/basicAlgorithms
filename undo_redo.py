import os

class my_stack:
    def __init__(self):
        self.cont = []
    
    def push(self, item):
        self.cont.append(item)

    def pop(self):
        if self.cont:
            return self.cont.pop()
        else:
            print('empty stack')
            raise IndexError
        
    def top(self):
        return self.cont[len(self.cont) - 1]
    
    def size(self):
        return len(self.cont)
    
    def empty(self):
        return not self.cont
    

glob_text = list()
glob_history = my_stack()


def WRITE(word):
    word = word + ' '
    toFile = open('anyText.txt', 'a')
    toFile.write(word)
    glob_text.append(word)
    toFile.close()

def READ():
    fromFile = open('anyText.txt')
    data = fromFile.read()
    print(data)
    fromFile.close()

def UNDO():
    if not glob_text:
        return
    last_word = glob_text[len(glob_text) - 1]
    glob_text.pop()
    glob_history.push(last_word)
    toFile = open('tmp.txt', 'w')
    for word in glob_text:
        toFile.write(word)
    toFile.close()
    os.remove('anyText.txt')
    os.rename('tmp.txt', 'anyText.txt')


def REDO():
    if glob_history.empty():
        return
    last_change = glob_history.top()
    glob_history.pop()
    glob_text.append(last_change)
    toFile = open('tmp.txt', 'a')
    for word in glob_text:
        toFile.write(word)
    toFile.close()
    os.remove('anyText.txt')
    os.rename('tmp.txt', 'anyText.txt')


WRITE('Hello World!!')
WRITE('How are you?')
WRITE('My name is')
WRITE('Artemis')
READ()
for i in range(len(glob_text) + 3):
    UNDO()
    READ()
for i in range(glob_history.size() + 3):
    REDO()
    READ()
for i in range(len(glob_text) - 1):
    UNDO()
    READ()