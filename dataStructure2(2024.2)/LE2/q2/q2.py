import random

# Classe para o nó da árvore
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1  # Necessário para AVL

# Implementação de uma Árvore Binária de Busca
class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        return root

    def in_order(self, root, result):
        if root:
            self.in_order(root.left, result)
            result.append(root.key)
            self.in_order(root.right, result)

    def pre_order(self, root, result):
        if root:
            result.append(root.key)
            self.pre_order(root.left, result)
            self.pre_order(root.right, result)

    def post_order(self, root, result):
        if root:
            self.post_order(root.left, result)
            self.post_order(root.right, result)
            result.append(root.key)

# Implementação de uma Árvore AVL
class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            return Node(key)

        if key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        # Atualizar a altura do nó atual
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # Obter o fator de balanceamento
        balance = self.get_balance(root)

        # Rotação para balancear a árvore
        # Rotação simples à direita
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)

        # Rotação simples à esquerda
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)

        # Rotação dupla esquerda-direita
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        # Rotação dupla direita-esquerda
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def get_height(self, root):
        if root is None:
            return 0
        return root.height

    def get_balance(self, root):
        if root is None:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)

    def left_rotate(self, z):
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    def right_rotate(self, z):
        y = z.left
        T3 = y.right

        y.right = z
        z.left = T3

        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    def in_order(self, root, result):
        if root:
            self.in_order(root.left, result)
            result.append(root.key)
            self.in_order(root.right, result)

    def pre_order(self, root, result):
        if root:
            result.append(root.key)
            self.pre_order(root.left, result)
            self.pre_order(root.right, result)

    def post_order(self, root, result):
        if root:
            self.post_order(root.left, result)
            self.post_order(root.right, result)
            result.append(root.key)

# Programa principal
if __name__ == "__main__":
    bst = BinarySearchTree()
    avl = AVLTree()

    # Gerar uma sequência aleatória de 50 números inteiros
    sequence = random.sample(range(1, 1000), 50)

    # Inserir os números na Árvore Binária de Busca
    for number in sequence:
        bst.root = bst.insert(bst.root, number)

    # Inserir os números na Árvore AVL
    for number in sequence:
        avl.root = avl.insert(avl.root, number)

    # Realizar os percursos
    bst_in_order, bst_pre_order, bst_post_order = [], [], []
    avl_in_order, avl_pre_order, avl_post_order = [], [], []

    bst.in_order(bst.root, bst_in_order)
    bst.pre_order(bst.root, bst_pre_order)
    bst.post_order(bst.root, bst_post_order)

    avl.in_order(avl.root, avl_in_order)
    avl.pre_order(avl.root, avl_pre_order)
    avl.post_order(avl.root, avl_post_order)

    # Exibir os percursos e comparar
    print("Árvore BST - Em Ordem:", bst_in_order)
    print("Árvore AVL - Em Ordem:", avl_in_order)
    print("Em Ordem: Iguais?" , bst_in_order == avl_in_order)

    print("\nÁrvore BST - Pré-Ordem:", bst_pre_order)
    print("Árvore AVL - Pré-Ordem:", avl_pre_order)
    print("Pré-Ordem: Iguais?" , bst_pre_order == avl_pre_order)

    print("\nÁrvore BST - Pós-Ordem:", bst_post_order)
    print("Árvore AVL - Pós-Ordem:", avl_post_order)
    print("Pós-Ordem: Iguais?" , bst_post_order == avl_post_order)