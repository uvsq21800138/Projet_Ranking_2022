# Variables
nbGraphes <- 6

# Fonctions
plots_for_one_graph <- function(name, id){
    # Ratio de sommets détruits
    data = read.table(paste0("datastudy/", name, "_ratio.data"))

    colnames(data) = c("alpha", "acc", "ratioSommetsDetruits", "ratioArcsDetruits")
    data080 = data[data$alpha == 0.80,]
    data085 = data[data$alpha == 0.85,]
    data090 = data[data$alpha == 0.90,]
    
    lowX = min(data$ratioSommetsDetruits)
    highX = max(data$ratioSommetsDetruits)
    lowY = min(data$acc)
    highY = max(data$acc)
    plot(data080$ratioSommetsDetruits, data080$acc, 
         pch = 20,
         cex = 0.5,
         xlim = c(lowX, highX),
         ylim = c(lowY, highY),
         xlab = "Ratio de sommets détruits",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à : bleu = 0.80, vert = 0.85, rouge = 0.90"))
    lines(lowess(data080$ratioSommetsDetruits, data080$acc, f = 0.3), col = "blue")
    points(data085$ratioSommetsDetruits, data085$acc, pch = 20, cex = 0.5, col = "green")
    lines(lowess(data085$ratioSommetsDetruits, data085$acc, f = 0.3), col = "green")
    points(data090$ratioSommetsDetruits, data090$acc, pch = 20, cex = 0.5, col = "red")
    lines(lowess(data090$ratioSommetsDetruits, data090$acc, f = 0.3), col = "red")

    #Ratio d'arcs détruits
    plot(data$ratioSommetsDetruits, data$ratioArcsDetruits, 
         pch = 20,
         cex = 0.5,
         xlab = "Ratio de sommets détruits",
         ylab = "Ratio d'arcs détruits",
         main = paste0(name, " (", id, "/", nbGraphes, ")"))
    lines(lowess(data$ratioSommetsDetruits, data$ratioArcsDetruits))

    # Alpha
    data = read.table(paste0("datastudy/", name, "_alpha.data"))

    colnames(data) = c("alpha", "acc", "ratioSommetsDetruits", "ratioArcsDetruits")
    data005 = data[data$ratioSommetsDetruits == 0.05,]
    data010 = data[data$ratioSommetsDetruits == 0.10,]
    data015 = data[data$ratioSommetsDetruits == 0.15,]

    lowX = min(data005$alpha, data010$alpha, data015$alpha)
    highX = max(data005$alpha, data010$alpha, data015$alpha)
    lowY = min(data005$acc, data010$acc, data015$acc)
    highY = max(data005$acc, data010$acc, data015$acc)
    plot(data005$alpha, data005$acc, 
         pch = 20,
         cex = 0.5,
         xlim = c(lowX, highX),
         ylim = c(lowY, highY),
         xlab = "Alpha",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nRatio fixé à : bleu = 0.05, vert = 0.10, rouge = 0.15"))
    lines(lowess(data005$alpha, data005$acc, f = 0.3), col = "blue")
    points(data010$alpha, data010$acc, pch = 20, cex = 0.5, col = "green")
    lines(lowess(data010$alpha, data010$acc, f = 0.3), col = "green")
    points(data015$alpha, data015$acc, pch = 20, cex = 0.5, col = "red")
    lines(lowess(data015$alpha, data015$acc, f = 0.3), col = "red")
}

# Main
plots_for_one_graph("wb-cs-stanford", 1)
plots_for_one_graph("Stanford", 2)
plots_for_one_graph("Stanford_BerkeleyV2", 3)
plots_for_one_graph("in-2004v2", 4)
plots_for_one_graph("wikipedia-20051105V2", 5)
plots_for_one_graph("wb-edu", 6)
