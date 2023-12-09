# 1.	Zadanie: Implementacja Kolejki (1 pkt)

Celem tego zadania jest zaimplementowanie podstawowej struktury danych – kolejki. Kolejka jest to abstrakcyjna struktura danych, która działa na zasadzie "first-in, first-out" (FIFO). Oznacza to, że elementy dodawane do kolejki są przechowywane w kolejności, w jakiej zostały dodane, i są pobierane z niej również w tej samej kolejności. Implementacja powinna być wykonana w dwóch wariantach: 
a)	z przechowywaniem danych w tablicy
b)	z przechowywaniem danych w postaci dynamicznie alokowanych obiektów

## Wymagania:
* Stały rozmiar: 10 elementów.
* Klasa Queue:
  * `enqueue(element)`: Dodaje element do kolejki.
  * `dequeue()`: Usuwa i zwraca element z początku kolejki.
  * `is_empty()`: Zwraca True, jeśli kolejka jest pusta, w przeciwnym razie False.
  * `size()`: Zwraca liczbę elementów w kolejce.

# 2.	Zadanie: Implementacja Stosu (1 pkt)

Celem tego zadania jest zaimplementowanie podstawowej struktury danych - stosu. Stos jest to abstrakcyjna struktura danych, która działa na zasadzie "last-in, first-out" (LIFO). Oznacza to, że ostatni element dodany do stosu jest pierwszy, który zostanie usunięty.
## Wymagania:
* Stały rozmiar: 10 elementów.
* Klasa Stack:
  * `push(element)`: Dodaje element na wierzchołek stosu.
  * `pop()`: Usuwa i zwraca element z wierzchołka stosu.
  * `is_empty()`: Zwraca True, jeśli stos jest pusty, w przeciwnym razie False.
  * `size()`: Zwraca liczbę elementów na stosie.
# 3.	Zadanie: Rozszerzenie implementacji stosu i kolejki (1 pkt)
Celem tego zadania jest rozszerzenie implementacji stosu i kolejki do formy, w której nie będzie stałej ilości elementów tzn. Ilość ta może się zmienić w czasie działania programu. Ponadto powinny być pokryte wszystkie skrajne przypadki

## Wymagania: 
* Zmienny rozmiar umiejscowionych elementów (Zwłaszcza w implemnetacji tablicowej jeśli struktura danych osiągnie maksymalny rozmiar, zaimplementuj mechanizm automatycznego rozszerzania tablicy, aby zmieścić więcej elementów)
* Obsłużyć przypadki gdy kolejka/stos nie posiadają elementów


# 4.  Zadanie: Zarządzanie pilnymi zgłoszeniami w wiosce (1pkt)

W małej wiosce Temerii pojawiły się zarówno potwory, jak i inne nagłe sytuacje, które wymagają uwagi Geralta. Mieszkańcy zgłaszają zarówno pojawienie się potworów, jak i inne pilne sprawy, takie jak pożary czy zagubienie dzieci. Wiedźmin musi skutecznie zarządzać obiema sytuacjami, dając pierwszeństwo zagrożonym mieszkańcom.

## Wymagania:
Napisz program, który reprezentuje zgłoszenia od mieszkańców jako elementy w strukturze danych. Wyróżniamy dwa typy zgłoszeń, które to pojawiają sie losowo:
 * Potwory, które pojawiają się w różnych częściach wioski,
 * Pilne sprawy wymagające szybkiej reakcji.

Geralt musi patrolować wioski, reagując na zgłoszenia w odpowiedniej kolejności, przy czym zagrożonym mieszkańcom zawsze przyznaje pierwszeństwo. Ponadto gdy Geralt pokona 10 potworów to musi złożyć sprawozdanie sołtysowi o ilości i kolejności pokonanych potworów w celu otrzymania nagrody.

# 5. Zadanie: Poszukiwanie (1pkt):
Właśnie zostałeś trenerem, który wyrusza w wędrówkę po świecie, szukając nowych i silnych Pokemonów. W czasie swojej podróży natknął się na parę tajemniczych lokalizacji, gdzie uważa się, że ukryte są legendarnie rzadkie gatunki Pokemonów. Musisz zbadać te lokalizacje i sprawdzić, czy gatunki Pokemonów, które tam żyją, są wystarczająco rzadkie.

## Wymagania:
Napisz funkcję, która przyjmuje zbiór lokalizacji (reprezentowanych przez losowo wygenerowane punkty [x,y] na płaszczyźnie) oraz minimalną odległość r (dowolna jednostka i wartość). Funkcja powinna sprawdzić odległość między każdą parą punktów w zbiorze. Jeśli odległość między jakąkolwiek parą punktów jest większa lub równa r, punkty te są uznawane za odległe i zostają dodane do stosu odległych lokalizacji, które chcesz zbadać.
