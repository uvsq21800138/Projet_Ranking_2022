# Variables
nbGraphes <- 6

# Fonctions
plots_for_one_graph <- function(name, id){
    # Ratio de sommets détruits
    data = read.table(paste0("datastudy/", name, "_ratio.data"))
    attach(data)

    alpha = V1
    acceleration = V2
    ratioSommetsDetruits = V3
    ratioArcsDetruits = V4

    data[data$alpha == 0.80,]
    
    plot(ratioSommetsDetruits, acceleration, 
         pch = 20,
         cex = 0.5,
         xlab = "Ratio de sommets détruits",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à : bleu = 0.80, vert = 0.85, rouge = 0.90"))
    lines(lowess(ratioSommetsDetruits, acceleration, f = 0.3), col = "blue")
    data[data$alpha == 0.85,]
    points(ratioSommetsDetruits, acceleration, pch = 20, cex = 0.5, col = "green")
    lines(lowess(ratioSommetsDetruits, acceleration, f = 0.3), col = "green")
    data[data$alpha == 0.90,]
    points(ratioSommetsDetruits, acceleration, pch = 20, cex = 0.5, col = "red")
    lines(lowess(ratioSommetsDetruits, acceleration, f = 0.3), col = "red")

    # Ratio d'arcs détruits
    plot(ratioSommetsDetruits, ratioArcsDetruits, 
         pch = 20,
         cex = 0.5,
         xlab = "Ratio de sommets détruits",
         ylab = "Ratio d'arcs détruits",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à : bleu = 0.80, vert = 0.85, rouge = 0.90"))
    lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")
    points(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, col = "green")
    lines(lowess(ratioSommetsDetruits, ratioArcsDetruits, f = 0.3), col = "green")
    points(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, col = "red")
    lines(lowess(ratioSommetsDetruits, ratioArcsDetruits, f = 0.3), col = "red")

    # Alpha
    data = read.table(paste0("datastudy/", name, "_alpha.data"))
    attach(data)

    alpha = V1
    acceleration = V2
    ratioSommetsDetruits = V3
    ratioArcsDetruits = V4

    plot(alpha, nbIterationsPagerank, 
         pch = 20,
         cex = 0.5,
         xlab = "Alpha",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nRatio fixé à : bleu = 0.05, vert = 0.10, rouge = 0.15"))
    lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
    points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "green")
    lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "green")
    points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
    lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")
}

# Main
plots_for_one_graph("wb-cs-stanford", 1)
plots_for_one_graph("Stanford", 2)
plots_for_one_graph("Stanford_BerkeleyV2", 3)
plots_for_one_graph("in-2004v2", 4)
plots_for_one_graph("wb-edu", 5)
plots_for_one_graph("wikipedia-20051105V2", 6)