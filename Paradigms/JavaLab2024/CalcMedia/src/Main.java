import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a quantidade de notas: ");
        int quantidade = scanner.nextInt();

        double[] numeros = new double[quantidade];
        double soma = 0;

        for (int i = 0; i < quantidade; i++) {
            System.out.print("Digite a nota " + (i + 1) + ": ");
            numeros[i] = scanner.nextDouble();
            soma += numeros[i];
        }

        double media = soma / quantidade;
        System.out.println("A média é: " + media);

        scanner.close();
    }
}
