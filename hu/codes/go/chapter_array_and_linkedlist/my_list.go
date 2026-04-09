// File: my_list.go
// Created Time: 2022-12-18
// Author: msk397 (machangxinq@gmail.com)

package chapter_array_and_linkedlist

/* Lista osztály */
type myList struct {
	arrCapacity int
	arr         []int
	arrSize     int
	extendRatio int
}

/* Konstruktor */
func newMyList() *myList {
	return &myList{
		arrCapacity: 10,              // Lista kapacitása
		arr:         make([]int, 10), // Tömb (lista elemeit tárolja)
		arrSize:     0,               // Lista hossza (jelenlegi elemszám)
		extendRatio: 2,               // Szorzó, amellyel a lista kapacitása minden alkalommal bővül
	}
}

/* Lista hosszának lekérése (jelenlegi elemszám) */
func (l *myList) size() int {
	return l.arrSize
}

/* Lista kapacitásának lekérése */
func (l *myList) capacity() int {
	return l.arrCapacity
}

/* Elem frissítése */
func (l *myList) get(index int) int {
	// Ha az index határon kívül esik, kivételt dob, mint alább
	if index < 0 || index >= l.arrSize {
		panic("Index out of bounds")
	}
	return l.arr[index]
}

/* Elem hozzáadása a végéhez */
func (l *myList) set(num, index int) {
	if index < 0 || index >= l.arrSize {
		panic("Index out of bounds")
	}
	l.arr[index] = num
}

/* Listaelemek közvetlen bejárása */
func (l *myList) add(num int) {
	// Ha az elemek száma meghaladja a kapacitást, aktiválódik a bővítési mechanizmus
	if l.arrSize == l.arrCapacity {
		l.extendCapacity()
	}
	l.arr[l.arrSize] = num
	// Elemszám frissítése
	l.arrSize++
}

/* Lista rendezése */
func (l *myList) insert(num, index int) {
	if index < 0 || index >= l.arrSize {
		panic("Index out of bounds")
	}
	// Ha az elemek száma meghaladja a kapacitást, aktiválódik a bővítési mechanizmus
	if l.arrSize == l.arrCapacity {
		l.extendCapacity()
	}
	// Toljuk hátra egy pozícióval az összes elemet az index pozíció után
	for j := l.arrSize - 1; j >= index; j-- {
		l.arr[j+1] = l.arr[j]
	}
	l.arr[index] = num
	// Elemszám frissítése
	l.arrSize++
}

/* Elem törlése */
func (l *myList) remove(index int) int {
	if index < 0 || index >= l.arrSize {
		panic("Index out of bounds")
	}
	num := l.arr[index]
	// Toljuk előre az összes elemet az index pozíció után
	for j := index; j < l.arrSize-1; j++ {
		l.arr[j] = l.arr[j+1]
	}
	// Elemszám frissítése
	l.arrSize--
	// A törölt elem visszaadása
	return num
}

/* Kapacitás bővítése */
func (l *myList) extendCapacity() {
	// Hozz létre egy új tömböt, amelynek hossza extendRatio-szorosa az eredetinek, és másold át az eredeti tömböt
	l.arr = append(l.arr, make([]int, l.arrCapacity*(l.extendRatio-1))...)
	// Kapacitás frissítése
	l.arrCapacity = len(l.arr)
}

/* Érvényes hosszú lista visszaadása */
func (l *myList) toArray() []int {
	// Elemek sorba állítása
	return l.arr[:l.arrSize]
}
