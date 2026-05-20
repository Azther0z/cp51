package deck;

import java.util.Arrays;

import card.base.Card;

public class Deck {
	// TODO: constructor
	private String name;
	private int deckSize;
	private Card[] deckList;

	public Deck(String name, Card[] deckList) {
		super();
		this.setName(name);
		this.setDeckList(deckList);
		this.setDeckSize();
	}

	// You CAN modify the first line
	public int insertCard(Card card) throws InsertCardFailedException {
		int count = 0;
		for (Card c : this.getDeckList()) {
			if (c.equals(card)) {
				count++;
			}
		}
		if (count >= 4)
			throw new InsertCardFailedException("You can only put 4 of the same cards into the deck");
		// FILL CODE HERE
		// You can use Arrays.copyOf(Original Array, New Length) to create new arrays
		// with bigger size
		// Must return new deckSize
		Card[] newDeck = (Card[]) Arrays.copyOf(this.getDeckList(), this.getDeckSize() + 1);
		newDeck[this.getDeckSize()] = card;
		this.setDeckList(newDeck);
		this.setDeckSize();
		return this.getDeckSize();
	}

	// You CAN modify the first line
	public Card removeCard(int slotNumber) throws RemoveCardFailedException {
		if (this.deckList.length <= slotNumber) {
			throw new RemoveCardFailedException("Number you insert exceed deck size");
		}
		if (this.deckList[slotNumber] == null) {
			throw new RemoveCardFailedException("There is no card in that slot");
		}
		// FILL CODE HERE
		// You can use Arrays.copyOf(Original Array, New Length) to create new arrays
		// with bigger size (Added slot is empty)
		// Once card is removed, other card down the list must rearrange to the empty
		// slot
		// Must return card that was removed
		Card[] newDeck = new Card[this.getDeckSize() - 1];
		int index = 0;
		Card removed = this.getDeckList()[slotNumber];
		for (int i = 0; i < this.getDeckSize(); i++) {
			if (i == slotNumber) {
				continue;
			}
			newDeck[index] = this.getDeckList()[i];
			index++;
		}
		this.setDeckList(newDeck);
		this.setDeckSize();
		return removed;
	}

	@Override
	public String toString() {
		return new StringBuilder().append("{").append(this.getName()).append("}").append("(").append(this.getDeckSize())
				.append(" deck size)").toString();
	}

	/* GETTERS & SETTERS */

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getDeckSize() {
		return deckSize;
	}

	public void setDeckSize() {
		this.deckSize = this.getDeckList().length;
	}

	public Card[] getDeckList() {
		return deckList;
	}

	public void setDeckList(Card[] deckList) {
		this.deckList = deckList.clone();
	}

}
