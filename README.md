# Obejktinio-Programavimo-LD

### v0.5:

Programa kuri originaliai buvo daryta tik su vectoriais, perkurta (atskirai) su deque, list konteinerių tipais. <br>
Išmatuoti greičiai: (deque greičių matavimas buvo atliktas su kitų kompiuteriu)

| Failų dydis: 1_000           | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 2         | 6      | 8     |
| Rikiavimas didėjimo tvarka   | 0         | 0      | 0     |
| Skirstymas į du konteinerius | 0         | 0      | 0     |

| Failų dydis: 10_000          | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 37        | 43     | 23    |
| Rikiavimas didėjimo tvarka   | 2         | 2      | 18    |
| Skirstymas į du konteinerius | 0         | 0      | 7     |

| Failų dydis: 100_000         | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 348       | 384    | 118   |
| Rikiavimas didėjimo tvarka   | 42        | 28     | 101   |
| Skirstymas į du konteinerius | 15        | 6      | 40    |

| Failų dydis: 1_000_000       | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 3432      | 3731   | 1154  |
| Rikiavimas didėjimo tvarka   | 496       | 410    | 1256  |
| Skirstymas į du konteinerius | 183       | 69     | 412   |

| Failų dydis: 10_000_000      | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 34522     | 45458  | 12037 |
| Rikiavimas didėjimo tvarka   | 5509      | 6329   | 8602  |
| Skirstymas į du konteinerius | 1839      | 668    | 4322  |

**Vectoriaus ir listo knoteinerių tipo testavimas atliktas su:**
<br>
Lenovo Legion Y530:
<br>
Procesorius: Intel(R) Core(TM) i7-8750H CPU @ 2.20GHz   2.21 GHz
<br>
RAM: 16,0 GB (15,9 GB usable)
<br>
Sistemos tipas: 64-bit operacinė sistema, x64 pagrindo procesorius
<br>
Kompiuterio atminties tipas: SSD
<br>

**Deque konteinerio tipo testavimas atliktas su:**
<br>
Lenovo Legion 5 15IMH05H:
<br>
Procesorius: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz   2.59 GHz
<br>
RAM: 16,0 GB (15,9 GB usable)
<br>
Sistemos tipas: 64-bit operacinė sistema, x64 pagrindo procesorius
<br>
Kompiuterio atminties tipas: SSD
<br>

### v0.4:

1. Pertvarkyta main funkcija, kad butu lengviau pasinaudojama funkcijomis.
2. Pridėta funkcija kuri sukuria atsitiktinių studentų failą pagal nurodytą dydi.
3. Pridėta funkcija kuri nuskaito studentų failą ir jį padalina į du : galvočių(kuriu galutinis vertinimas yra >= 5) ir nuskriastūjų (galutinis < 5)

2 ir 3 punktų veikimo greičiai yra matuojami.

### v0.3:

Programos failai išskirstyti per kelis failus.

### v0.2: 

Pridėjau būdą nuskaityti studentus iš atskiro duomenų failo, ir juos atspausdinti "out.txt" faile.

### v0.1:

Čia aš  viešinu savo savo atliekamus labaratorinius darbus.

Ši programa prašo vartotojo irašyti studentų vardus, pavardes, atitinkamą namų darbų kiekį, egzamino pažimį.

Tada ši programa duoda pasirinti: ar skaičiuoti studentų palutinius pažimius su namų darbų medianą, ar su namų darbų vidurkiu.

Galutinis pažimys yra skaičiuojamas pagal formulę:


$Galutinis = 0.4 * vidurkis + 0.6 * egzaminas$ </br>
arba: </br>
$Galutinis = 0.4 * mediana + 0.6 * egzaminas$

Ir galiausiai išvedama informacija:

Pavardė | Vardas | Galutinis pažimys

