function cadastrarProduto()
    // Solicita informações do produto ao usuário
    codigo = input("Digite o código do produto: ");
    nome = input("Digite o nome do produto: ", "s");
    preco = input("Digite o preço do produto: ");

    // Salva as informações em um arquivo de texto
    fid = mopen("produtos.txt", "a");
    mfprintf(fid, "%d\t%s\t%.2f\n", codigo, nome, preco);
    mclose(fid);
    
    disp("Produto cadastrado com sucesso!");
endfunction

// Chamando a função para cadastrar o produto
cadastrarProduto();

disp("Cadastro de produto concluído com sucesso!");
