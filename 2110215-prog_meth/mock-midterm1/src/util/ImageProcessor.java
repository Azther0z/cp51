package util;

import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.io.*;
import java.net.URISyntaxException;
import java.nio.file.*;
import javax.imageio.ImageIO;

public class ImageProcessor {

    public static double[] process(String filename) {
        InputStream is = getImageInputStream(filename);
        if (is == null) {
            System.out.println("Image not found");
            System.exit(1);
        }
        try {
            BufferedImage originalImage = ImageIO.read(is);
            if (originalImage == null) {
                System.out.println("Image not found");
                System.exit(1);
            }
            BufferedImage grayscaleImage = convertToGrayscale(originalImage, 28, 28);
            return normalizeImage(grayscaleImage);
        } catch (IOException e) {
            System.out.println("Image not found");
            System.exit(1);
        }
        return null; // Unreachable
    }

    private static InputStream getImageInputStream(String filename) {
        InputStream is = ImageProcessor.class.getResourceAsStream("/" + filename);
        if (is != null) {
            System.out.println("Image loaded from JAR resource.");
            return is;
        }
        Path jarDir = getJarDirectory();
        Path imagePath = jarDir.resolve("image").resolve(filename);
        if (Files.exists(imagePath)) {
            System.out.println("Image loaded from: " + imagePath.toAbsolutePath());
            try {
                return new FileInputStream(imagePath.toFile());
            } catch (FileNotFoundException e) {
                System.err.println("Image not found");
            }
        }
        return null;
    }

    private static Path getJarDirectory() {
        try {
            return Paths.get(ImageProcessor.class.getProtectionDomain()
                    .getCodeSource().getLocation().toURI()).getParent();
        } catch (URISyntaxException e) {
            return Paths.get("").toAbsolutePath();
        }
    }

    private static BufferedImage convertToGrayscale(BufferedImage originalImage, int width, int height) {
        BufferedImage grayscaleImage = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);
        grayscaleImage.getGraphics().drawImage(originalImage, 0, 0, width, height, null);
        return grayscaleImage;
    }

    private static double[] normalizeImage(BufferedImage image) {
        byte[] pixels = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();
        double[] normalizedPixels = new double[pixels.length];
        for (int i = 0; i < pixels.length; i++) {
            normalizedPixels[i] = (pixels[i] & 0xFF) / 255.0;
        }
        return normalizedPixels;
    }
}
