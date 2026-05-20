package logic;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class CardUtil {
	public static boolean isExistsInList(UnitCard card, ArrayList<UnitCard> list) {
		for (UnitCard unitCard : list) {
			if (unitCard.equals(card)) {
				return true;
			}
		}
		return false;
	}

	public static boolean isExistsInList(UnitDeck deck, ArrayList<UnitDeck> list) {
		for (UnitDeck unitDeck : list) {
			if (unitDeck.equals(deck)) {
				return true;
			}
		}
		return false;
	}

	public static boolean cardExistsInDeckList(ArrayList<UnitDeck> deckList, UnitCard cardToTest) {
		for (UnitDeck unitDeck : deckList) {
			if (unitDeck.existsInDeck(cardToTest)) {
				return true;
			}
		}
		return false;
	}

	public static ArrayList<UnitCard> getCardsFromFile(String filename) {
		File fileToRead = new File(filename);
		ArrayList<UnitCard> cardsFromFile = new ArrayList<UnitCard>();
		Scanner s = null;
		try {
			s = new Scanner(fileToRead);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("Cannot find file!");
			return null;
		}
		while (s.hasNextLine()) {
			String line = s.nextLine();
			String[] data = line.split(",");
			String name = data[0];
			int bloodCost;
			int power;
			int health;
			try {
				bloodCost = Integer.parseInt(data[1]);
				power = Integer.parseInt(data[2]);
				health = Integer.parseInt(data[3]);
			} catch (NumberFormatException e) {
				// TODO Auto-generated catch block
				System.out.println("File contains string with incorrect format!");
				s.close();
				return null;
			}
			String flavorText = data[4];
			UnitCard card = new UnitCard(name, bloodCost, power, health, flavorText);
			cardsFromFile.add(card);
		}
		s.close();
		return cardsFromFile;

	}

	public static void printCardList(ArrayList<UnitCard> cardList, boolean verbose) {
		for (int i = 0; i < cardList.size(); i++) {
			System.out.println(i + ") " + cardList.get(i));
			if (verbose) {
				System.out.println("Blood Cost: " + cardList.get(i).getBloodCost());
				System.out.println(cardList.get(i).getFlavorText());
				if (i < cardList.size() - 1)
					System.out.println("-----");
			}
		}

	}

	public static void printDeck(UnitDeck unitDeck) {

		if (unitDeck.getCardsInDeck().size() == 0) {
			System.out.println("EMPTY DECK");
		} else {
			for (CardCounter cc : unitDeck.getCardsInDeck()) {
				System.out.println(cc);
			}
		}

		System.out.println("Total Cards: " + unitDeck.cardCount());
	}

	public static void printDeckList(ArrayList<UnitDeck> deckList) {

		for (int i = 0; i < deckList.size(); i++) {
			System.out.println(i + ") " + deckList.get(i).getDeckName());
			printDeck(deckList.get(i));
			if (i < deckList.size() - 1)
				System.out.println("-----");
		}
	}
}
