################################## wb-cs-stanford ##################################
nom <- "datastudy/wb-cs-stanford"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")

################################## Stanford ##################################
nom <- "datastudy/Stanford"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")

################################## Stanford_BerkeleyV2 ##################################
nom <- "datastudy/Stanford_BerkeleyV2"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")

################################## in-2004v2 ##################################
nom <- "datastudy/in-2004v2"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")

################################## wb-edu ##################################
nom <- "datastudy/wb-edu"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")

################################## wikipedia-20051105V2 ##################################
nom <- "datastudy/wikipedia-20051105V2"

# ratio de sommets détruits
data = read.table(paste0(nom, "_ratio.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.8")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

# ratio d'arcs détruits
plot(ratioSommetsDetruits, ratioArcsDetruits, type = "p", xlab = "Ratio de sommets détruits", ylab = "Ratio d'arcs détruits",
col = "blue", main = "alpha fixé à 0.8")

# alpha
data = read.table(paste0(nom, "_alpha.data"))
attach(data)

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "p", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.2")
lines(nbIterationsCustom, alpha, col = "red")