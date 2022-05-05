# Variables
nbGraphes <- 6

################################## wb-cs-stanford ##################################
nom <- "wb-cs-stanford"
id <- 1

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")

################################## Stanford ##################################
nom <- "Stanford"
id <- 2

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")

################################## Stanford_BerkeleyV2 ##################################
nom <- "Stanford_BerkeleyV2"
id <- 3

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")

################################## in-2004v2 ##################################
nom <- "in-2004v2"
id <- 4

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")

################################## wb-edu ##################################
nom <- "wb-edu"
id <- 5

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")

################################## wikipedia-20051105V2 ##################################
nom <- "wikipedia-20051105V2"
id <- 6

# Ratio de sommets détruits
data = read.table(paste0("datastudy/", nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Alpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, nbIterationsPagerank, f = 0.3), col = "blue")
points(ratioSommetsDetruits, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(ratioSommetsDetruits, nbIterationsCustom, f = 0.3), col = "red")

# Ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, pch = 20, cex = 0.5, xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nAlpha fixé à 0.8"))
lines(lowess(ratioSommetsDetruits, ratioArcsDetruits), col = "blue")

# Alpha
data = read.table(paste0("datastudy/", nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(alpha, nbIterationsPagerank, pch = 20, cex = 0.5, xlab = "Alpha", ylab = "Nombre d'itérations avant convergence", col = "blue",
main = paste0(nom, " (", id, "/", nbGraphes, ")", "\nBleu = Pagerank, Rouge = Custom, Ratio fixé à 0.2"))
lines(lowess(alpha, nbIterationsPagerank, f = 0.3), col = "blue")
points(alpha, nbIterationsCustom, pch = 20, cex = 0.5, col = "red")
lines(lowess(alpha, nbIterationsCustom, f = 0.3), col = "red")