#include <robotOnLine.h>

robotOnLine robot; // Criar um objeto chamado "robot"

void setup()
{
  robot.begin();	// Configura os pinos.
  
  robot.beginAutoDrive();	//	Inicia a função de condução autónoma.
}

void loop()
{
  int info = 0; // Variável para guardar o numero devolvido pela função autoDrive().
  int command = 0; // variável para lembrar que comandos já foram executados.

  info = robot.autoDrive(0); // Aqui copiamos o valor devolvido pela função para a variável info.

  /* Sempre que usarem a função autoDrive() têm de enviar um valor, estes são as instruções aceites:
      0 -> Enviar 0 ou qualquer outro número (até 255) não listado se não quiser dar instruções ao robô.
      1 -> Enviar 1 para colocar o robô a rodar para a direita até encontrar uma linha.
      2 -> Enviar 2 para colocar o robô a rodar para a esquerda até encontrar uma linha.
      3 -> Enviar 3 para dizer ao robô para seguir em frente.
      4 -> Enviar 4 para dizer ao robô para recuar, tenha em atenção que o robô pode-se desalinhar 
           ligeiramente devido à roda traseira.
  */
}
