# Obejktinio-Programavimo-LD

<details>
<summary> Naudojimosi instruksija</summary>

Pasileidus programa terminale pasirodys tekstas prašantis pasirinki ką jūs norite daryti, variantai yra:
 * I programą ikelti studentus iš atitinkamo sudentų duomenų failo.
 * Išvesti esamus(suvestus) studentus į failą pavadinimu "out.txt".
 * Suvedinėti studentus per konsolę.
 * Testavimui sukurti atsitiktinių studentų duomenų.
 * Testavimui sukurti atsitiktinių studentų duomenų failą.
 * Turimą studentų duomenų failą nnuskaityti ir iš jo sukurti du naujus: išlaikiusių ir ne.
 
 * Baigus programos naudojimus iveskite 'n', tai išvalys visą esamą informaciją ir užbaigs veikimą.
 
 * P.S. jei testuojate ir turite 5 studentų failus: studentai1000.txt, studentai10000.txt, studentai100000.txt, studentai1000000.txt, studentai10000000.txt. Galite ivesti raide 't', kuri pratestuos visus šiuos failus automatiškai.
</details>


<details>
<summary> v1.1  </summary>

Lentelėse laikas yra matuotas sekundėmis, matavimas atliktas su vectoriaus tipo konteineriu.
|         Failo   dydis 1_000_000         | class | struct |
|:---------------------------------------:|-------|--------|
| Nuksaitymas is   failo I konteineri     | 6.692 | 6.278  |
| Studentu     rikiavimas didejimo tvarka | 0.847 | 0.811  |
| Studentu     skirstymas I dvi grupes    | 0.203 | 0.291  |
|                                         |       |        |
|           Failo dydis 100_000           | class | struct |
| Nuksaitymas is   failo I konteineri     | 0.679 | 0.626  |
| Studentu     rikiavimas didejimo tvarka | 0.067 | 0.088  |
| Studentu     skirstymas I dvi grupes    | 0.019 | 0.027  |

|                       | O1     | O2     | O3     |
|-----------------------|--------|--------|--------|
| Memory of .exe file:  | 197 KB | 196 KB | 200 KB |

Rezultatai: 
 * Struct yra greitesni nuskaitymuose ir rikiavimuose.
 * Class yra gretesnis studentų skirstime.


</details>

<!-- ============================================================================================================================================================ -->
<details>
<summary> v1.0 ir ankstesnės versijos </summary>

<details>
<summary> v1.0: </summary>
**Pirmo ir antro metodo atilkimo greičių lentelės, rezultatai**

| Pirmas metodas:                       |           |        |        | Antras metodas: |           |        |        |
|---------------------------------------|-----------|--------|--------|-----------------|-----------|--------|--------|
| Failu dydis: 1_000                    | Vectoriai | Listai | Deckai |                 | Vectoriai | Listai | Deckai |
| Nuksaitymas is   failo I konteineri   | 0         | 0      | 0      |                 | 0         | 0      | 0      |
| Studentu   rikiavimas didejimo tvarka | 0         | 0      | 0      |                 | 0         | 0      | 0      |
| studentu   skirstymas I dvi grupes    | 0         | 0      | 0      |                 | 0         | 0      | 0      |
|                                       |           |        |        |                 |           |        |        |
| Failu dydis: 10_000                   | Vectoriai | Listai | Deckai |                 | Vectoriai | Listai | Deckai |
| Nuksaitymas is   failo I konteineri   | 0,024     | 0,015  | 0,015  |                 | 0,018     | 0,015  | 0,031  |
| Studentu   rikiavimas didejimo tvarka | 0,015     | 0      | 0,017  |                 | 0,002     | 0      | 0,015  |
| studentu   skirstymas I dvi grupes    | 0         | 0      | 0      |                 | 0         | 0,015  | 0      |
|                                       |           |        |        |                 |           |        |        |
| Failu dydis: 100_000                  | Vectoriai | Listai | Deckai |                 | Vectoriai | Listai | Deckai |
| Nuksaitymas is   failo I konteineri   | 0,175     | 0,112  | 0,209  |                 | 0,162     | 0,197  | 0,212  |
| Studentu   rikiavimas didejimo tvarka | 0,05      | 0,012  | 0,169  |                 | 0,042     | 0,03   | 0,172  |
| studentu   skirstymas I dvi grupes    | 0,018     | 0,04   | 0,06   |                 | 0,018     | 0,05   | 0,05   |
|                                       |           |        |        |                 |           |        |        |
| Failu dydis: 1_000_000                | Vectoriai | Listai | Deckai |                 | Vectoriai | Listai | Deckai |
| Nuksaitymas is   failo I konteineri   | 1,69      | 1,227  | 1,991  |                 | 1,703     | 1,985  | 1,992  |
| Studentu   rikiavimas didejimo tvarka | 0,594     | 0,379  | 2,196  |                 | 0,593     | 0,525  | 2,187  |
| studentu   skirstymas I dvi grupes    | 0,211     | 0,441  | 0,657  |                 | 0,211     | 0,649  | 0,589  |
|                                       |           |        |        |                 |           |        |        |
| Failu dydis: 10_000_000               | Vectoriai | Listai | Deckai |                 | Vectoriai | Listai | Deckai |
| Nuksaitymas is   failo I konteineri   | 16,593    | 11,755 | 20,454 |                 | 16,62     | 19,965 | 20,318 |
| Studentu   rikiavimas didejimo tvarka | 7,252     | 6,431  | 26,761 |                 | 7,258     | 8,571  | 26,507 |
| studentu   skirstymas I dvi grupes    | 2,326     | 4,614  | 30,169 |                 | 2,172     | 6,65   | 8,031  |

Testavimo metu taip pat buvoma apytkisliai tikrinama kiek RAM naudoja programa, veikdama su dydžiausiu failų dydžių (10_000_000). Rezultatai:
| Matuota GB | Pirmas metodas:          | Antras metodas: |
|------------|--------------------------|-----------------|
| Vectoriai  | 1,7                      | 1,4             |
| Listai     | 4,1                      | 3               |
| Deckai     | 13+(kompiuterio limitas) | 11              |

Rezultatų apibendrinimas:
1. Kompiuterio atminties mažiausiai naudojo vectoriai!
2. Pirmos ir antros strategijos vectorių greičiai yra beveik tokie patys.
3. Listai, nors ir ne patys greičiausi, bet optimizavimas su juo parodė dydžiasius pagreitėjimus, bei atminties sutaupymus.
4. Kažkas negerai su decku veikla testavimo kompiuterije.(laikai labai ilgi, RAM 'ryja' labai daug, paskutinis testavimas pirmoje versijoje LABAI pastrigo)

<details>
<summary>Testavimo kompiuterio info. </summary>

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

</details>

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
</details>
