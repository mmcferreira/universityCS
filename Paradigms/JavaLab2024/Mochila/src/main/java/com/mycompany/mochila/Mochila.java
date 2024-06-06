/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.mochila;

class bolsa {
    int tamanho;
    String marca;
    String material;
}

public class Mochila {

    public static void main(String[] args) {
        bolsa mochila1 = new bolsa();
        System.out.println("Mateus Magalhaes e Thiago da Costa \n");
        System.out.println("\nArquivo: Mochila.java\n");
        mochila1.tamanho = 20;
        mochila1.marca = "Nike";
        mochila1.material = "Nylon";
        
        System.out.println("A mochila tem tamanho para " + mochila1.tamanho + " litros, foi fabricada pela marca " + mochila1.marca + " e foi feito de " + mochila1.material);
        
        
        bolsa mochila2 = new bolsa();
        mochila2.tamanho = 15;
        mochila2.marca = "Lacoste";
        mochila2.material = "couro";
        
        System.out.println("A mochila tem tamanho para " + mochila2.tamanho + " litros, foi fabricada pela marca " + mochila2.marca + " e foi feito de " + mochila2.material);
    }
}
