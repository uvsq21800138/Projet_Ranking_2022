# Variables
nbGraphes <- 6

# Fonctions
plots_for_one_graph <- function(name, id){
    # Ratio de sommets détruits
    data = read.table(paste0("datastudy/", name, "_ratio.data"))
    data080 <- data[data$V1 == 0.8,]
    data085 <- data[data$V1 == 0.85,]
    data090 <- data[data$V1 == 0.9,]

    #alpha = V1
    #acceleration = V2
    #ratioSommetsDetruits = V3
    #ratioArcsDetruits = V4

    lowY = min(data$V2)
    highY = max(data$V2)
    
    plot(data080$V3, data080$V2, 
         pch = 20,
         cex = 0.5,
         ylim = c(lowY, highY),
         xlab = "Ratio de sommets détruits",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à : bleu = 0.80, vert = 0.85, rouge = 0.90"))
    lines(lowess(data080$V3, data080$V2, f = 0.3), col = "blue")
    points(data085$V3, data085$V2, pch = 20, cex = 0.5, col = "green")
    lines(lowess(data085$V3, data085$V2, f = 0.3), col = "green")
    points(data090$V3, data090$V2, pch = 20, cex = 0.5, col = "red")
    lines(lowess(data090$V3, data090$V2, f = 0.3), col = "red")

    # Ratio d'arcs détruits
    lowY = min(data$V4)
    highY = max(data$V4)

    plot(data080$V3, data080$V4, 
         pch = 20,
         cex = 0.5,
         ylim = c(lowY, highY),
         xlab = "Ratio de sommets détruits",
         ylab = "Ratio d'arcs détruits",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à : bleu = 0.80, vert = 0.85, rouge = 0.90"))
    lines(lowess(data080$V3, data080$V4), col = "blue")
    points(data085$V3, data085$V4, pch = 20, cex = 0.5, col = "green")
    lines(lowess(data085$V3, data085$V4, f = 0.3), col = "green")
    points(data090$V3, data090$V4, pch = 20, cex = 0.5, col = "red")
    lines(lowess(data090$V3, data090$V4, f = 0.3), col = "red")

    # Alpha
    data = read.table(paste0("datastudy/", name, "_alpha.data"))
    data005 <- data[data$V3 == 0.05,]
    data010 <- data[data$V3 == 0.1,]
    data015 <- data[data$V3 == 0.15,]

    #alpha = V1
    #acceleration = V2
    #ratioSommetsDetruits = V3
    #ratioArcsDetruits = V4

    lowY = min(data$V2)
    highY = max(data$V2)

    plot(data005$V1, data005$V2, 
         pch = 20,
         cex = 0.5,
         ylim = c(lowY, highY),
         xlab = "Alpha",
         ylab = "Accélération de l'algorithme custom (%)",
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nRatio fixé à : bleu = 0.05, vert = 0.10, rouge = 0.15"))
    lines(lowess(data005$V1, data005$V2, f = 0.3), col = "blue")
    points(data010$V1, data010$V2, pch = 20, cex = 0.5, col = "green")
    lines(lowess(data010$V1, data010$V2, f = 0.3), col = "green")
    points(data015$V1, data015$V2, pch = 20, cex = 0.5, col = "red")
    lines(lowess(data015$V1, data015$V2, f = 0.3), col = "red")
}

# Main
plots_for_one_graph("wb-cs-stanford", 1)
plots_for_one_graph("Stanford", 2)
plots_for_one_graph("Stanford_BerkeleyV2", 3)
plots_for_one_graph("in-2004v2", 4)
plots_for_one_graph("wb-edu", 5)
plots_for_one_graph("wikipedia-20051105V2", 6)