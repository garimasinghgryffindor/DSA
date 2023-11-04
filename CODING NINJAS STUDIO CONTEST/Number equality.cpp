int canSheMakeEqual(int X, int Y) {
    if(Y > X) return canSheMakeEqual(Y, X);
    if(X == Y) return 1;
    if((X-Y) % 3 == 0) return 1;
    return 0;
}
