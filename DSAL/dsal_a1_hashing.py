
class HashTable:
    def __init__(self, size: int) -> None:
        self.record = []
        self.m = size

        # initialize all records with 0 and -1 link
        for _ in range(size):
            self.record.append([0, "", -1])  # [tel,name,link]

    def display_table(self) -> None:
        for rec in self.record:
            print(rec)

    def hash_function(self, tel: int) -> int:
        key = (tel % self.m)
        return key

    def generate_table(self,recs:list[list]) -> None:
        for rec in recs:
            self.insert_rec(rec)

    def insert_rec(self, rec: list) -> None:
        key = self.hash_function(rec[0])
        if (self.record[key][0] == 0):
            # no collision
            self.record[key][0] = rec[0]
            self.record[key][1] = rec[1]
            self.record[key][2] = -1
        else:  # collision
            if (self.hash_function(self.record[key][0]) == key):
                # create link
                last_elmt = key
                while (self.record[last_elmt][2] != -1):
                    last_elmt = self.record[last_elmt][2]
                k = last_elmt
                while (self.record[k][0] != 0):
                    k = ((k+1) % self.m)
                self.record[last_elmt][2] = k
                self.record[k][0] = rec[0]
                self.record[k][1] = rec[1]
                self.record[k][2] = -1
            else:  # replacement
                # find last link
                for i in range(self.m):
                    if(self.record[i][2] == key):
                        prev_link_key = i
                
                old_rec_tel = self.record[key][0]
                old_rec_name = self.record[key][1]
                old_rec_link = self.record[key][2]

                self.record[key][0] = rec[0]
                self.record[key][1] = rec[1]
                self.record[key][2] = -1

                k = key
                while (self.record[k][0] != 0):
                    k = ((k+1) % self.m)

                self.record[prev_link_key][2] = k
                self.record[k][0] = old_rec_tel
                self.record[k][1] = old_rec_name
                self.record[k][2] = old_rec_link


def input_records(n: int) -> list[list]:
    records = []
    for i in range(n):
        name = input("Enter Name of the person:")
        tel = int(input("Enter Telephone Number:"))
        records.append([tel, name])
    return records


def main() -> None:
    n = int(input("Enter the total number of records:"))
    records = input_records(n)
    t1 = HashTable(n)
    t1.generate_table(records)
    t1.display_table()




if __name__ == "__main__":
    main()

"""
5
sahil
963
akhil
783
yash
664
om
555
parthya
622
"""
