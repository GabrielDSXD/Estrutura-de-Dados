package application;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;

//Eu queria fazer 3 telas pra trocar entre si tela inicial, tela1 e tela 2
public class Main extends Application {
	
	@Override
	public void start(Stage stage) throws Exception {
		
		try {
			System.out.println("Iniciando o jogo...");
		
			Parent root = FXMLLoader.load(getClass().getResource("TelaInicial.fxml"));
			Scene scene = new Scene(root,1300, 800);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
		
			Image icon = new Image("iconeDado.png");
			stage.getIcons().add(icon);
			stage.setTitle("Estrutura de dados");
			stage.setResizable(false);
		
			stage.setScene(scene);
			stage.show();
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
		System.out.println("Fechando o jogo...");
	}
	

}
