# Orion: Zero Knowledge Proof with Linear Prover Time

Orion is a high-speed zero-knowledge proof system, that achieves $O(N)$ prover time of field operations and hash functions and $O(\log^2 N)$ proof size.

This repo provides a C++ implmenetation of Orion polynomial commitment, that can be coupled with other proof systems like (Virgo/Ligero/Hyrax/Spartan...) to achieve linear time zero-knowledge proofs. 

Note that this library has not received a security review or audit.

# Highlights

### General Polynomial Commitment
We supports both univariant and multivariant polynomial commitment schemes. 
### Succinct proof size
The proof size of our system is $O(\log^2 N)$
### State-of-the-art performance
We offers the fastest prover that can prove $2^{27}$ coefficients within $100$s in single thread mode.
### Expander testing
We offer our expander testing protocol for people to setup their own expander.

# Interface

Our main expander generation is defined in ```linear_code/linear_code_encode.h```

Our main PC interface is defined in ```include/VPD/linearPC.h```

To use our protocol, you need to first generate a expander:

```
int col_size = XXX, row_size = N / col_size;
expander_init(row_size);
```

Then commit your secret coefficient array using:

```
auto h = commit(coefs, N);
```

You can open the polynomial at a given point x using:
```
auto result = open_and_verify(x, N, h);
```

