# cross product operator:
`%cross3%` <- function(u,v) c(u[2]*v[3]-u[3]*v[2], u[3]*v[1]-u[1]*v[3], u[1]*v[2]-u[2]*v[1])

library("onion")
library("deSolve")
freeRigid <- function(t, y, parms, ...) {
	with(as.list(parms), {
		#cat("y= ", y, "\n")
		w <- y
		wdot <- NULL
		wdot[1] <- (lam[2]-lam[3])*w[2]*w[3]/lam[1]
		wdot[2] <- (lam[3]-lam[1])*w[3]*w[1]/lam[2]
		wdot[3] <- (lam[1]-lam[2])*w[1]*w[2]/lam[3]
		#cat("wdot= ", wdot, "\n")
		list(c(wdot[1], wdot[2], wdot[3]))
	})
}

yini <- c(0,0.01, 10)
times <- seq(from=0, by=0.001, to=20)
lam <- c(1,1.1,1.05)
parms <- list(lam=lam)
# computationally intensive:
traj <- ode(y= yini, func=freeRigid, times= times, parms=parms, method="rk4")
traj <- data.frame(traj)
layout(matrix(1:3, ncol=1))
plot(traj$time, traj$X1, type="l")
plot(traj$time, traj$X2, type="l")
plot(traj$time, traj$X3, type="l")

attitude <- matrix(c(1,0,0, 0,1,0, 0,0,1), nrow=3)
drot <- quaternion()
attitude.hist <- list()
dt <- diff(times)[1]

w.mod <- sqrt(traj$X1^2+traj$X2^2+traj$X3^2)
drot <- dt*quaternion(Re=w.mod, i=traj$X1/w.mod, j=traj$X2/w.mod, k=traj$X3/w.mod)
rot <- cumprod(rev(drot))
# computationally intensive:
attitude.hist <- lapply(rot, function(H) rotate(attitude, H))

attitude.hist

w.dum <- data.frame(w1=rep(1, 100), w2=rep(0.1, 100), w3=rep(0, 100))
w.dum.mod <- sqrt(w.dum$w1+w.dum$w3+w.dum$w2)
drot.dum <- dt*quaternion(Re=w.dum.mod, i=w.dum$w1, j=w.dum$w1, k=w.dum$w3)
rot.dum <- cumprod(rev(drot.dum))
library("scatterplot3d")
scatterplot3d(x=w.dum$w1, y=w.dum$w2, z=w.dum$w3)
scatterplot3d(0,0,0, xlim = c(-1,1), ylim = c(-1,1), zlim = c(-1,1))
att0 <- matrix(c(1,0,0, 0,1,0, 0,0,1), nrow=3)
for (i in 1:length(rot.dum)) {
	att <- rotate(att0, rot.dum[i])
	scatterplot3d(att[1,1], att[1,2], att[1,3], color= "red", add=T,
		      xlim = c(-1,1), ylim = c(-1,1), zlim = c(-1,1))
	scatterplot3d(att[2,1], att[2,2], att[2,3], color= "green", add=T,
		      xlim = c(-1,1), ylim = c(-1,1), zlim = c(-1,1))
	scatterplot3d(att[3,1], att[3,2], att[3,3], color= "blue", add=T,
		      xlim = c(-1,1), ylim = c(-1,1), zlim = c(-1,1))
}
x <- seq(from=0, to=2*pi, length.out = 300)
scatterplot3d(x, cos(x), sin(x))
