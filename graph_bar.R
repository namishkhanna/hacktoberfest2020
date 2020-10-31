bancodesangue <- data.frame("tipo" = 1:4,"quantidade"=1:4)
 
bancodesangue$tipo <- c("A","B", "O", "AB")
 
bancodesangue$quantidade <- c(16,6,15,3)

rotulo <- c("Tipos de sangue", "Quantidade")

par(mgp=c(1,1,0))
 
png(filename = "quest1-b-barra.png", width = 800, height = 600)

barplot(bancodesangue$quantidade, main="Banco de sangue", xlab=rotulo[1], ylab=rotulo[2], names.arg = bancodesangue$tipo, ylim=c(0, 20), cex.names = 0.8, xaxs = "i")

grid(nx=NA, ny=NULL)
 
barplot(bancodesangue$quantidade, main="Banco de sangue", xlab=rotulo[1], ylab=rotulo[2],col = c("green1","springgreen2","seagreen", "yellowgreen"), names.arg = bancodesangue$tipo, ylim=c(0, 20), cex.names = 0.8, xaxs = "i", add=TRUE)


dev.off()
