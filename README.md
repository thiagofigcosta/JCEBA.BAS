# JCEBA.BAS
Joguinho de controle de estoque de bomba atômica.BAS

		Instruções para compilar (no arquivo loadLibs.h tem opcoes para usar ou nao alut e soil):
			Dependencias:-lglut -lGLU -lGL -lm -lopenal -lGLEW (-lSOIL -lalut apenas se definir alguma opcao no loadLibs.h como 1)
		Para compilar windows basta abrir o projeto no codeBlocks
		(disponivel para linux e windows)
		Para compilar linux e rodar o programa basta abrir o terminal na pasta do mesmo e digitar "make rerun", "make run" ou "make all"
				-make rerun- compila, limpa arquivos temporarios,executa;
				-make run- compila, executa;
				-make all- compila.
				-ver makefile para outras opções(make install nao implementado)

		=================================================================
		Itens Obrigatorios Implementados:
			TODOS

		Itens Adicionais Implementados:

		-Video:
			https://www.youtube.com/watch?v=59J2it0dCgc
		-Relativas a texturas:
			-personagem morrendo
			-personagem atirando
			-projétil voando
			-projétil explodindo
		-Relativas ao cenário:
			-cenário não plano
				-cenário aleatório
			-cenário destrutível
				-parcialmente complexo(o jogador respeita a gravidade mas o cenário não)
		-Relativas aos personagens e projéteis:
			-movimentação
			-vidas
			-projétil orientado
		-Relativas ao jogo:
			-Vento
			-Inteligêngia artificial(3 dificuldades)
		-Outras funcionalidades:
			-modo cheat
			-manter razão de aspecto
			-Telas
			-sons
			-implementação criativa:
				-modo campanha: o jogador avança e luta contra diferentes oponentes
				-opções alteráveis relativas ao jogo,a geração de mapas e linguagem do jogo(5 idiomas)
				-instruções de jogo
				-escolha de personagens
				-opcoes salvas em arquivos
				-projéteis variáveis
				-cenários variáveis(música temática variável)
				-animações ao andar,cair,explosoes ou sofrer dano
				-modo fullscreen
				-multiplataforma
				-modo bug secreto, divertido
				-outros detalhes
