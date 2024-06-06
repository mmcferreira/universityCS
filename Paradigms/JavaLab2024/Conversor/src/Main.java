import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um número decimal: ");
        int decimal = scanner.nextInt();

        String binario = converterParaBinario(decimal);

        System.out.println("O número decimal " + decimal + " em binário é: " + binario);
    }

    public static String converterParaBinario(int decimal) {
        if (decimal == 0) {
            return "0";
        }

        StringBuilder binario = new StringBuilder();

        while (decimal > 0) {
            int resto = decimal % 2;
            binario.insert(0, resto);
            decimal = decimal / 2;
        }

        return binario.toString();
    }
}
