import java.util.Scanner;

public class Calculadora {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o 1º número:");
        double num1 = scanner.nextDouble();

        System.out.println("Digite o 2º número:");
        double num2 = scanner.nextDouble();

        System.out.println("Digite a operação desejada ( + , - , * , / ):");
        char op = scanner.next().charAt(0);

        scanner.close();

        double resultado;

        switch (op)
        {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                } else {
                    System.out.println("Erro! Divisão por zero não é permitida.");
                    return;
                }
                break;
            default:
                System.out.println("Erro! Operação inválida.");
                return;
        }

        System.out.println("O resultado é: " + resultado);
    }
}