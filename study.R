### wb-cs-stanford ###
modelname = "datastudy/wb-cs-stanfordratio.csv"
data = read.table(modelname)
attach(data);

alpha = V1
nbIterationsPagerank = V2
nbIterationsCustom = V3
ratioSommetsDetruits = V4
ratioArcsDetruits = V5

plot(ratioSommetsDetruits, nbIterationsPagerank, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Ratio de sommets détruits",
col = "blue", main = "Nombre d'itérations avant convergence selon le ratio de sommets détruits, alpha = 0.3")

points(ratioSommetsDetruits, nbIterationsCustom, col = "red")
lines(ratioSommetsDetruits, nbIterationsCustom, col = "red")

### Stanford ###



### Stanford_BerkeleyV2 ###



### in-2004v2 ###



### wb-edu.txt ###



### wikipedia-20051105V2 ###

