install.packages("vegan")
library(vegan)


# build a matrix 
test <- matrix(c(0, 0, 0, 0, 0,
                 2, 0, 0, 0, 0,
                 6, 5, 0, 0, 0,
                 10, 9, 4, 0, 0, 
                 9, 8, 5, 3, 0), nrow=5, ncol = 5)

clust_teste<-vegdist (test, method = "jaccard")
plot(hclust(clust_teste, method="average"), hang=-1)
