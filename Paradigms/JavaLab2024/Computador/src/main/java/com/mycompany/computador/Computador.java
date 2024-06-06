/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.computador;

class Pc {
    int ram;
    String marca;
    String processador;
}



public class Computador {

    public static void main(String[] args) {
        Pc pc1 = new Pc ();
        System.out.println("Mateus Magalhaes e Thiago da Costa \n");
        System.out.println("\nArquivo: Computador.java\n");
        pc1.ram = 12;
        pc1.marca = "Lenovo";
        pc1.processador = "AMD Ryzen 7 5500 u";
        
        System.out.println("O computador tem " + pc1.ram + "GB de memoria RAM, foi fabricado pela marca " + pc1.marca + "e tem o processador "+ pc1.processador);
    }
}
