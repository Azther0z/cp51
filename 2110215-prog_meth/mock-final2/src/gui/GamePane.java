package gui;

import javafx.scene.layout.GridPane;
import logic.GameSystem;
import logic.Map;

import java.util.ArrayList;
import java.util.List;

public class GamePane extends GridPane {
    private static final int GAME_SIZE = 620;
    private static GamePane instance;
    private List<List<CellPane>> gridCellPane;
    private double tileSize;

    private GamePane() {
        super();
        this.setPrefWidth(GAME_SIZE);
        this.setPrefHeight(GAME_SIZE);
    }

    public static GamePane getInstance() {
        if (instance == null) {
            instance = new GamePane();
        }
        return instance;
    }

    public void initTiles() {
        this.getChildren().clear();
        Map map = GameSystem.getInstance().getCurrentMap();
        this.tileSize = GAME_SIZE / (Math.max(map.getWidth(), map.getHeight()) * 1.0);
        this.gridCellPane = new ArrayList<List<CellPane>>();

        for(int i=0;i<map.getHeight();i++) {
        	ArrayList<CellPane> cellPaneList = new ArrayList<CellPane>();
        	for(int j=0;j<map.getWidth();j++) {
        		CellPane cellPane = new CellPane(tileSize,tileSize,i,j);
        		this.add(cellPane, j, i);
        		cellPaneList.add(cellPane);
        	}
        	this.gridCellPane.add(cellPaneList);
        }

    }

    public CellPane getCellPane(int row,int col){
        return this.gridCellPane.get(row).get(col);
    }


}
