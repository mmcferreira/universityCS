import heapq                            # manipulação de heaps
import networkx as nx                   # manipular grafos -> visualizar árvore binária
import matplotlib.pyplot as plt         # gerar grafos -> desenhar a árvore binária

class Prioridade:
    def __init__(self):   # self é instância atual da classe
        self.contador = 0  # mantém a ordem de chegada
        self.heap = []     # armazena em formato de heap

    def inserir(self, prioridade, dados):  # insere item na fila de prioridade
        heapq.heappush(self.heap, (-prioridade, self.contador, dados))
        self.contador += 1  # Incrementa o contador para manter a ordem de chegada

    def esta_vazia(self):  # verifica se a fila de prioridade está vazia!
        return len(self.heap) == 0

    def remover(self):  # remove o elemento com maior prioridade
        if self.heap:
            prioridade, ordem_chegada, dado = heapq.heappop(self.heap)
            return (-prioridade, ordem_chegada + 1, dado)
        else:
            raise IndexError("Fila vazia")

    def __len__(self):  # retorna o tamanho da fila (corrigido o nome do método)
        return len(self.heap)

    def gerar_arvore_grafica(self, nome_arquivo="arvore_heap.png"):
        G = nx.DiGraph()  # adiciona grafo, mostra hierarquia da árvore
        pos = {}  # dicionário que armazena posição dos nós
        labels = {}  # dicionário que rotula os nós

        def adicionar_no(posicao, indice):  # adiciona o nó atual ao gráfico
            if indice < len(self.heap):
                prioridade, ordem_chegada, dado = self.heap[indice]
                G.add_node(indice)  # adiciona o nó no gráfico
                pos[indice] = (indice, -posicao)
                labels[indice] = f"P:{-prioridade}\nC:{dado}"  # define rótulo do nó com prioridade e dado

                # filho esquerdo
                if 2 * indice + 1 < len(self.heap):  # verifica baseado no tamanho
                    G.add_edge(indice, 2 * indice + 1)  # adiciona nova aresta
                    adicionar_no(posicao + 1, 2 * indice + 1)  # chama a função recursivamente pro filho esquerdo

                # filho direito
                if 2 * indice + 2 < len(self.heap):  # verifica baseado no tamanho
                    G.add_edge(indice, 2 * indice + 2)  # adiciona nova aresta
                    adicionar_no(posicao + 1, 2 * indice + 2)  # chama a função recursivamente pro filho direito

        adicionar_no(0, 0)  # chamada inicial

        # desenha o gráfico
        plt.figure(figsize=(12, 8))
        nx.draw(G, pos, with_labels=True, labels=labels, node_size=2000, node_color="lightblue", font_size=10, font_weight="bold", font_color="black")
        plt.title("Visualização da Árvore Binária (Max-Heap)")

        # salva a imagem num arquivo
        plt.savefig(nome_arquivo)
        print(f"Árvore binária salva em {nome_arquivo}")
