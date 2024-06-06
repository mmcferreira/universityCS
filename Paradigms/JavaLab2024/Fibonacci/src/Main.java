import java.util.Scanner;

public class Main {

    public static int calcularFibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite a posição na sequência de Fibonacci: ");
        int posicao = scanner.nextInt();

        int resultado = calcularFibonacci(posicao);
        System.out.println("O número de Fibonacci na posição " + posicao + " é " + resultado);

        scanner.close();
    }
}
