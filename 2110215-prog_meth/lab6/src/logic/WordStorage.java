package logic;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class WordStorage {

	private static ArrayList<String> wordList;

	public static void init() {
		wordList = new ArrayList<String>();

		populateWordList();

	}

	public static void populateWordList() {
		try (InputStream is = WordStorage.class.getResourceAsStream("/logic/words.txt")) {
			if (is == null) {
				throw new IllegalStateException("Resource not found: /logic/words.txt");
			}
			try (Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(is)))) {
				while (sc.hasNextLine()) {
					String line = sc.nextLine().trim();
					if (!line.isEmpty()) {
						wordList.add(line);
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static boolean isWordInList(String word) {
		if (word.length() != 5) {
			return false;
		}
		return wordList.contains(word);
	}

	public static String getRandomWord() {
		int idx = new Random().nextInt(wordList.size());
		return wordList.get(idx);
	}
}
