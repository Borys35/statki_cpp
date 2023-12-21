# Gra w statki
## Opis sztucznej inteligencji
Sztuczna inteligencja, który został zaimplementowany w grze, to tak naprawdę algorytm, który oblicza wszystkie możliwości ruchu i wykonuje losowy, legalny ruch. Ponadto, Algorytm stara się zachowywać się podobnie do człowieka. Przykładowo, który komputer trafi w pole na którym jest statek gracza, komputer podejmuje próbę strzału obok wcześniej trafionego pola.
## Sztuczna inteligencja podczas fazy ustawiania statków
Podczas fazy ustawiania statków, algorytm na początku sprawdza wszystkie pola i ustala, na których z nich może położyć swoje statki. Wybór legalnych pól odbywa się za pomocą funkcji rand, czyli liczb pseudolosowych. Proces jest jak najbardziej zbliżony do sposobu, w który człowiek mógłby rozstawić swoje statki.
## Sztuczna inteligencja podczas „bitwy”
Podczas fazy, w której gracz i przeciwnik na zmianę strzelają w swoje plansze, komputer losowo wybiera pola, w które może strzelić (tj. nie są już zestrzelone przez komputer i mieszczą się na planszy). Wyjątkiem pełnej losowości w strzałach jest moment, gdy komputer trafi w statek przeciwnika. W tym momencie algorytm wybiera jeden z maksymalnie czterech sąsiednich pól, czyli jedynych możliwych pól, gdzie może znajdować się dalsza część statku. Jeśli komputer znajdzie drugie pole, na którym jest statek. Komputer próbuje strzelać w jednej linii dopóki nie chybi lub nie napotka granicy mapy.
## Sztuczna inteligencja, a rozmiar mapy
Gra ma do wyboru mapy 3x3, 5x5, 7x7, 10x10 i 12x12. Algorytm na każdej mapie radzi sobie podobnie, bez większych problemów. Oczywiście algorytm mógłby być bardziej rozszerzony o inne ulepszenia, natomiast rozmiar mapy nieszczególnie wpływa na umiejętności algorytmu. Program wydaje się nie zwalniać przy większej mapie.
# Trudności podczas tworzeniu projektu
Głównymi trudnościami była implementacja algorytmu sztucznej inteligencji, a przede wszystkim algorytmu podczas strzelania. Algorytm pod tym względem wymaga przeanalizowania każdego możliwego scenariusza, a tych scenariuszy potrafi być bardzo dużo.
