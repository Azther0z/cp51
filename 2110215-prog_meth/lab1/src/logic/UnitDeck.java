package logic;

import java.util.ArrayList;
import java.util.Objects;

public class UnitDeck {

	private ArrayList<CardCounter> cardsInDeck;
	private String deckName;

	public UnitDeck(String deckName) {
		super();
		this.setCardsInDeck(new ArrayList<CardCounter>());
		this.setDeckName(deckName);
	}

	public String getDeckName() {
		return deckName;
	}

	public void setDeckName(String deckName) {
		if (deckName.isBlank()) {
			this.deckName = "Untitled Deck";
		} else {
			this.deckName = deckName;
		}
	}

	public ArrayList<CardCounter> getCardsInDeck() {
		return cardsInDeck;
	}
	
	public void setCardsInDeck(ArrayList<CardCounter> cardsInDeck) {
		this.cardsInDeck = cardsInDeck;
	}

	public void addCard(UnitCard newCard, int count) {
		if (count <= 0)
			return;
		boolean added = false;
		for (CardCounter cardCounter : this.cardsInDeck) {
			if (cardCounter.getCard().equals(newCard)) {
				int tmp = cardCounter.getCount();
				cardCounter.setCount(tmp + count);
				added = true;
				break;
			}
		}
		if (!added) {
			CardCounter newCardCounter = new CardCounter(newCard, count);
			cardsInDeck.add(newCardCounter);
		}
	}

	public void removeCard(UnitCard toRemove, int count) {
		if (count <= 0) {
			return;
		}
		for (CardCounter cardCounter : this.cardsInDeck) {
			if (toRemove.equals(cardCounter.getCard())) {
				if (cardCounter.getCount() - count <= 0) {
					this.cardsInDeck.remove(cardCounter);
					break;
				} else {
					cardCounter.setCount(cardCounter.getCount() - count);
					break;
				}
			}
		}
	}

	public int cardCount() {
		int count = 0;
		for (CardCounter cardCounter : this.cardsInDeck) {
			count += cardCounter.getCount();
		}
		return count;
	}

	public boolean existsInDeck(UnitCard card) {
		for (CardCounter cardCounter : this.cardsInDeck) {
			if (card.equals(cardCounter.getCard())) {
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		UnitDeck other = (UnitDeck) obj;
		return Objects.equals(deckName, other.deckName);
	}

}
