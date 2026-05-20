package gui;

import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import logic.GameLogic;
import logic.SquareMark;
import logic.SquareState;
import javafx.event.EventHandler;
import javafx.geometry.Insets;

public class MineSweeperSquare extends Pane {
	private boolean isDrawn;
	private Color baseColor;
	private int xPosition;
	private int yPosition;
	private final String oURL;
	final private String oneURL;
	final private String mineURL;
	final private String flagURL;

	public MineSweeperSquare(int x, int y) {
		super();
		oURL = "o.png";
		oneURL = "one.png";
		mineURL = "mine.png";
		flagURL = "flag.png";
		this.setxPosition(x);
		this.setyPosition(y);
		this.setPrefHeight(100);
		this.setPrefWidth(100);
		this.setMinHeight(100);
		this.setMinWidth(100);
		this.setBaseColor(Color.MOCCASIN);
		initializeCellColor();
		this.setOnMouseClicked(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				onClickHandler();
			}
		});
	}

	public boolean isDrawn() {
		return isDrawn;
	}

	public void setDrawn(boolean isDrawn) {
		this.isDrawn = isDrawn;
	}

	public int getxPosition() {
		return xPosition;
	}

	public void setxPosition(int xPosition) {
		this.xPosition = xPosition;
	}

	public int getyPosition() {
		return yPosition;
	}

	public void setyPosition(int yPosition) {
		this.yPosition = yPosition;
	}

	public Color getBaseColor() {
		return baseColor;
	}

	public void setBaseColor(Color baseColor) {
		this.baseColor = baseColor;
	}

	private void onClickHandler() {
		if (GameLogic.getInstance().isGameEnd()) {
			return;
		}
		boolean secured = GameLogic.getInstance().isSecureMode();
		SquareState ss = GameLogic.getInstance().getBoardState()[this.getxPosition()][this.getyPosition()];
		if (!secured && ss != SquareState.REVEALED) {
			SquareMark sm = GameLogic.getInstance().getBoardMark()[this.getxPosition()][this.getyPosition()];
			if (sm == SquareMark.ONE) {
				String image_path = ClassLoader.getSystemResource(oneURL).toString();
				draw(new Image(image_path), Color.ORANGE);
			} else if (sm == SquareMark.NOTHING) {
				String image_path = ClassLoader.getSystemResource(oURL).toString();
				draw(new Image(image_path), Color.YELLOW);
			} else if (sm == SquareMark.MINE) {
				String image_path = ClassLoader.getSystemResource(mineURL).toString();
				draw(new Image(image_path), Color.RED);
			}
			GameLogic.getInstance().updateState(xPosition, yPosition, SquareState.REVEALED);
		}
		else if (secured && ss != SquareState.REVEALED) {
			String image_path = ClassLoader.getSystemResource(flagURL).toString();
			draw(new Image(image_path),Color.GREEN);
			GameLogic.getInstance().updateState(xPosition, yPosition, SquareState.SECURED);
		}
	}

	private void draw(Image image, Color backgroundColor) {
		BackgroundFill bgFill = new BackgroundFill(backgroundColor, CornerRadii.EMPTY, Insets.EMPTY);
		BackgroundFill[] bgFillA = { bgFill };
		BackgroundSize bgSize = new BackgroundSize(100, 100, false, false, false, false);
		BackgroundImage bgImg = new BackgroundImage(image, null, null, null, bgSize);
		BackgroundImage[] bgImgA = { bgImg };
		this.setBackground(new Background(bgFillA, bgImgA));
		this.setDrawn(true);
	}
	
	public void initializeCellColor() {
		BackgroundFill bgFill = new BackgroundFill(this.getBaseColor(),CornerRadii.EMPTY,Insets.EMPTY);
		this.setBackground(new Background(bgFill));
		this.setDrawn(false);
	}

}
