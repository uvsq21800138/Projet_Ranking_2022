nbGraphes <- 6

plots_for_one_graph <- function(name, id){
    # Ratio de sommets détruits
    data = read.table(paste0("datastudy/", name, "_ratio.data"))
    attach(data)

    alpha = V1
    nbIterationsPagerank = V2
    nbIterationsCustom = V3
    ratioSommetsDetruits = V4
    ratioArcsDetruits = V5

    lowY = min(nbIterationsPagerank, nbIterationsCustom)
    highY = max(nbIterationsPagerank, nbIterationsCustom)
    
    plot(ratioSommetsDetruits, nbIterationsPagerank, 
         pch = 20, 
         cex = 0.5, 
         xlim=c(0, 0.5), 
         ylim=c(lowY, highY),
         xlab = "Ratio de sommets détruits", 
         ylab = "Nombre d'itérations avant convergence", 
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8")
    )
    lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), 
          col = "blue")
    points(ratioSommetsDetruits, nbIterationsCustom, 
           pch = 20, 
           cex = 0.5, 
           col = "red"
    )
    lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), 
          col = "red")

    # Ratio d'arcs détruits
    plot(ratioSommetsDetruits, ratioArcsDetruits, 
         pch = 20, 
         cex = 0.5, 
         xlab = "Ratio de sommets détruits", 
         ylab = "Ratio d'arcs détruits", 
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8")
    )
    lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), 
          col = "blue")

    # Alpha
    data = read.table(paste0("datastudy/", name, "_alpha.data"))
    attach(data)

    alpha = V1
    nbIterationsPagerank = V2
    nbIterationsCustom = V3
    ratioSommetsDetruits = V4
    ratioArcsDetruits = V5

    lowY = min(nbIterationsPagerank, nbIterationsCustom)
    highY = max(nbIterationsPagerank, nbIterationsCustom)

    plot(alpha, nbIterationsPagerank, 
         pch = 20, 
         cex = 0.5, 
         xlim=c(0.5, 1), 
         ylim=c(lowY, highY),
         xlab = "Alpha", 
         ylab = "Nombre d'itérations avant convergence", 
         col = "blue",
         main = paste0(name, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2")
    )
    lines(lowess(alpha, nbIterationsPagerank, f = 0.3), 
          col = "blue")
    points(alpha, nbIterationsCustom, 
           pch = 20, 
           cex = 0.5, 
           col = "red"
    )
    lines(lowess(alpha, nbIterationsCustom, f = 0.3), 
          col = "red")
}

plots_for_one_graph("wb-cs-stanford", 1)
plots_for_one_graph("Stanford", 2)
plots_for_one_graph("Stanford_BerkeleyV2", 3)
plots_for_one_graph("in-2004v2", 4)
plots_for_one_graph("wb-edu", 5)
plots_for_one_graph("wikipedia-20051105V2", 6)

