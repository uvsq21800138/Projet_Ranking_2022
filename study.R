### wb-cs-stanford ###
# ratio
data = read.table("datastudy/wb-cs-stanford_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/wb-cs-stanford_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")

### Stanford ###
# ratio
data = read.table("datastudy/Stanford_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/Stanford_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")

### Stanford_BerkeleyV2 ###
# ratio
data = read.table("datastudy/Stanford_BerkeleyV2_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/Stanford_BerkeleyV2_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")

### in-2004v2 ###
# ratio
data = read.table("datastudy/in-2004v2_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/in-2004v2_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")

### wb-edu ###
# ratio
data = read.table("datastudy/wb-edu_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/wb-edu_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")

### wikipedia-20051105V2 ###
# ratio
data = read.table("datastudy/wikipedia-20051105V2_ratio.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, ratioSommetsDetruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, alpha fixé à 0.6")
lines(nbIterationsCustom, ratioSommetsDetruits, col = "red")

#alpha
data = read.table("datastudy/wikipedia-20051105V2_alpha.data")
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(nbIterationsPagerank, alpha, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "alpha",
col = "blue", main = "Bleu = Pagerank, Rouge = Custom, ratio fixé à 0.3")
lines(nbIterationsCustom, alpha, col = "red")