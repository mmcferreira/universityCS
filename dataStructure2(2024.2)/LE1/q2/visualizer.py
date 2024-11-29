from maxheap import Prioridade
import random

def gerar_clientes_aleatorios(quantidade):
    fila = Prioridade()
    
    # Inserir clientes com prioridades aleatórias
    for i in range(1, quantidade + 1):
        prioridade_aleatoria = random.randint(1, 10)
        cliente_nome = f"Cliente {i}"
        fila.inserir(prioridade_aleatoria, cliente_nome)

    return fila

# Gerar fila de prioridade
fila = gerar_clientes_aleatorios(10)

# Visualizar a árvore binária gerada pelo heap
fila.gerar_arvore_grafica(nome_arquivo="arvore_heap.png")

# Exibir os clientes em ordem de prioridade (da maior para a menor)
print("Clientes em ordem de prioridade (da maior para a menor):")
while not fila.esta_vazia():
    prioridade, ordem_chegada, cliente = fila.remover()
    print(f"Prioridade: {prioridade}, Nome: {cliente}, Ordem de chegada: {ordem_chegada}")
