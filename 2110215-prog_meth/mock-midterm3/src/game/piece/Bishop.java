package game.piece;

import java.util.Set;

import game.board.Board;
import game.position.Position;
import game.util.Movement;

public class Bishop extends Piece {

	public Bishop(boolean white, Position position, Board board) {
		super(white, position, board);
	}

	@Override
	public Set<Position> getLegalMove() {
		Movement movement = new Movement(this.getPosition(), this.getBoard());
		movement.getMovePositions(this);
		return movement.getMoves();
	}

	@Override
	public Object deepCopy() {
		Bishop bishop = new Bishop(this.isWhite(), this.getPosition(), this.getBoard());
		bishop.setMoved(this.isMoved());
		return bishop;
	}

}
