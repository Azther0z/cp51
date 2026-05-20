package gui;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;

public class ControlGridPane extends VBox {
	private final String miningImageURL;
	private ControlPane controlPane;
	
	public ControlGridPane(ControlPane controlPane) {
		super();
		this.controlPane = controlPane;
		miningImageURL = "bitcoin.png";
		String image_path = ClassLoader.getSystemResource(miningImageURL).toString(); // Most safe, best practice
		ImageView iv = new ImageView(new Image(image_path));
		iv.setFitHeight(150);
		iv.setFitWidth(150);
		BorderPane bp = new BorderPane();
		bp.setPrefWidth(150);
		bp.setPrefHeight(200);
		bp.setCenter(iv);
		this.getChildren().addAll(bp,this.controlPane);
	}
}
