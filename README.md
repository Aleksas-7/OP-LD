# Obejktinio-Programavimo-LD

v1.0:


<details>
<summary> v0.5: </summary>

Programa kuri originaliai buvo daryta tik su vectoriais, perkurta (atskirai) su deque, list konteinerių tipais. <br>
Išmatuoti greičiai: (deque greičių matavimas buvo atliktas su kitu kompiuteriu).<br>
Laikas matuotas sekundėmis.

| Failų dydis: 1_000           | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 0         | 0,01   | 0     |
| Rikiavimas didėjimo tvarka   | 0         | 0      | 0     |
| Skirstymas į du konteinerius | 0         | 0      | 0     |

| Failų dydis: 10_000          | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 0,04      | 0,04   | 0,02  |
| Rikiavimas didėjimo tvarka   | 0         | 0      | 0,02  |
| Skirstymas į du konteinerius | 0         | 0      | 0,01  |

| Failų dydis: 100_000         | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 0,35      | 0,38   | 0,12  |
| Rikiavimas didėjimo tvarka   | 0,04      | 0,03   | 0,1   |
| Skirstymas į du konteinerius | 0,02      | 0,01   | 0,04  |

| Failų dydis: 1_000_000       | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 3,43      | 3,73   | 1,15  |
| Rikiavimas didėjimo tvarka   | 0,5       | 0,41   | 1,26  |
| Skirstymas į du konteinerius | 0,18      | 0,07   | 0,41  |

| Failų dydis: 10_000_000      | Vectoriai | Listai | Deque |
|------------------------------|-----------|--------|-------|
| Nuskaitymas iš failo         | 34,52     | 45,46  | 12,04 |
| Rikiavimas didėjimo tvarka   | 5,51      | 6,33   | 8,6   |
| Skirstymas į du konteinerius | 1,84      | 0,67   | 4,32  |

**Vectoriaus ir listo konteinerių tipo testavimas atliktas su:**
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

</details>
<details>
<summary> v0.4: </summary>

1. Pertvarkyta main funkcija, kad butu lengviau pasinaudojama funkcijomis.
2. Pridėta funkcija kuri sukuria atsitiktinių studentų failą pagal nurodytą dydi.
3. Pridėta funkcija kuri nuskaito studentų failą ir jį padalina į du : galvočių(kuriu galutinis vertinimas yra >= 5) ir nuskriastūjų (galutinis < 5)

2 ir 3 punktų veikimo greičiai yra matuojami.

</details>
<details>
<summary> v0.3: </summary>

Programos failai išskirstyti per kelis failus.

</details>
<details>
<summary> v0.2: </summary>

Pridėjau būdą nuskaityti studentus iš atskiro duomenų failo, ir juos atspausdinti "out.txt" faile.

</details>
<details> 

<summary> v0.1: </summary>

Čia aš  viešinu savo savo atliekamus labaratorinius darbus.

Ši programa prašo vartotojo irašyti studentų vardus, pavardes, atitinkamą namų darbų kiekį, egzamino pažimį.

Tada ši programa duoda pasirinti: ar skaičiuoti studentų palutinius pažimius su namų darbų medianą, ar su namų darbų vidurkiu.

Galutinis pažimys yra skaičiuojamas pagal formulę:


$Galutinis = 0.4 * vidurkis + 0.6 * egzaminas$ </br>
arba: </br>
$Galutinis = 0.4 * mediana + 0.6 * egzaminas$

Ir galiausiai išvedama informacija:

Pavardė | Vardas | Galutinis pažimys

</details>
