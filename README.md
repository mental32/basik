# Basik
## A GW BASIC dialect.

> *DISCLAIMER:* The readme is decorative, the source is not operational.

Basik is a GW BASIC dialect and superset language.

## Examples

### GW BASIC

#### "stars" demo

The stars demo is used to demonstrate:
 - User input
 - Explicit type through the `$` operator.
 - Iteration: for loops and goto loops

```
10 INPUT "What is your name: "; U$
20 PRINT "Hello "; U$
30 INPUT "How many stars do you want: "; N
40 S$ = ""
50 FOR I = 1 TO N
60 S$ = S$ + "*"
70 NEXT I
80 PRINT S$
90 INPUT "Do you want more stars? "; A$
100 IF LEN(A$) = 0 THEN GOTO 90
110 A$ = LEFT$(A$, 1)
120 IF A$ = "Y" OR A$ = "y" THEN GOTO 30
130 PRINT "Goodbye "; U$
140 END
```

`user@host>basik stars.bas`




## Installing

`make` and `make install` should just about do it.

