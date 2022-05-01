### TESTS ###
modelname = "datastudy/graphetest.data"
data = read.table(modelname)
attach(data);

NbItérationsAvantConvergencePagerank = V1
NbItérationsAvantConvergenceCustom = V2
ProportionSommetsDétruits = V3
ProportionArcsDétruits = V4
Alpha = V5

plot(NbItérationsAvantConvergence, NbSommetsDétruits, type = "l", xlab = "Nombre d'itérations avant convergence", ylab = "Proportion de sommets détruits",
col = "red", main = "Nombre d'itérations avant convergence selon la proportion de sommets détruits, alpha = 0.3")

### Etude wb-cs-stanford ###
modelname = "datastudy/wb-cs-stanford.data"
data = read.table(modelname)
attach(data);

### Etude Stanford ###
modelname = "datastudy/Stanford.data"
data = read.table(modelname)
attach(data);

### Etude StanfordBerkeley ###
modelname = "datastudy/StanfordBerkeley.data"
data = read.table(modelname)
attach(data);

### Etude Inde ###
modelname = "datastudy/Inde.data"
data = read.table(modelname)
attach(data);

### Etude Web_edu ###
modelname = "datastudy/Web_edu.data"
data = read.table(modelname)
attach(data);

### Etude Wikipedia2005 ###
modelname = "datastudy/Wikipedia2005.data"
data = read.table(modelname)
attach(data);