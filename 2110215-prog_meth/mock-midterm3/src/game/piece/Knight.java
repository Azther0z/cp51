package game.piece;

import java.util.Set;

import game.board.Board;
import game.position.Position;
import game.util.Movement;

public class Knight extends Piece {

	public Knight(boolean white, Position position, Board board) {
		super(white, position, board);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Set<Position> getLegalMove() {
		Movement movement = new Movement(this.getPosition(), this.getBoard());
		movement.getMovePositions(this);
		return movement.getMoves();
	}

	@Override
	public Object deepCopy() {
		Knight knight = new Knight(this.isWhite(), this.getPosition(), this.getBoard());
		knight.setMoved(this.isMoved());
		return knight;
	}

}
