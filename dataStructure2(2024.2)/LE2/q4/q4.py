import random

class Node:
    def __init__(self, key, color, left=None, right=None):
        self.key = key
        self.color = color  # True for Red, False for Black
        self.left = left
        self.right = right

class RedBlackTree:
    def __init__(self):
        self.root = None

    def is_red(self, node):
        return node is not None and node.color

    def rotate_left(self, h):
        assert self.is_red(h.right)  # A rotação só ocorre com um nó vermelho à direita
        x = h.right
        h.right = x.left
        x.left = h
        x.color = h.color
        h.color = True
        return x

    def rotate_right(self, h):
        assert self.is_red(h.left)  # A rotação só ocorre com um nó vermelho à esquerda
        x = h.left
        h.left = x.right
        x.right = h
        x.color = h.color
        h.color = True
        return x

    def flip_colors(self, h):
        assert not self.is_red(h) and self.is_red(h.left) and self.is_red(h.right)
        h.color = True
        h.left.color = False
        h.right.color = False

    def insert(self, h, key):
        if h is None:
            return Node(key, True)  # Novo nó é vermelho

        if key < h.key:
            h.left = self.insert(h.left, key)
        elif key > h.key:
            h.right = self.insert(h.right, key)

        # Corrige a árvore para manter as propriedades
        if self.is_red(h.right) and not self.is_red(h.left):
            h = self.rotate_left(h)
        if self.is_red(h.left) and self.is_red(h.left.left):
            h = self.rotate_right(h)
        if self.is_red(h.left) and self.is_red(h.right):
            self.flip_colors(h)

        return h

    def add(self, key):
        self.root = self.insert(self.root, key)
        if self.root is not None:
            self.root.color = False  # A raiz é sempre preta

    def height(self):
        if self.root is None:
            return 0
        
        # Usando uma fila para realizar uma travessia por nível (BFS)
        queue = [(self.root, 1)]  # Cada elemento da fila é uma tupla (nó, altura)
        max_height = 0

        while queue:
            node, level = queue.pop(0)
            max_height = max(max_height, level)
            
            # Adiciona os filhos à fila
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        return max_height

# Testando a implementação
if __name__ == "__main__":
    rbt = RedBlackTree()

    # Criando uma sequência aleatória de 10.000 números inteiros
    random_numbers = random.sample(range(1, 100000), 10000)

    # Inserindo os números na Árvore Vermelha-Preta
    for num in random_numbers:
        rbt.add(num)

    # Calculando e exibindo a altura da árvore
    print(f"Altura da Árvore Vermelha-Preta: {rbt.height()}")
