class ListNode78ts { constructor(public val:number, public next:ListNode78ts|null=null){} }

export function mergeKLists(lists: (ListNode78ts|null)[]): ListNode78ts|null {
    const heap: ListNode78ts[] = lists.filter(Boolean) as ListNode78ts[];
    heap.sort((a,b)=>a.val-b.val);
    const dummy = new ListNode78ts(0); let cur = dummy;
    while (heap.length) {
        const node = heap.shift()!; cur.next=node; cur=cur.next;
        if (node.next) {
            let i=0; while(i<heap.length&&heap[i].val<=node.next.val)i++;
            heap.splice(i,0,node.next);
        }
    }
    return dummy.next;
}

function fl78(vals:number[]):ListNode78ts|null{const d=new ListNode78ts(0);let c=d;for(const v of vals){c.next=new ListNode78ts(v);c=c.next;}return d.next;}
function tl78(h:ListNode78ts|null):number[]{const r:number[]=[];while(h){r.push(h.val);h=h.next;}return r;}

export function problem78(): void {
    console.log("Problem 78:");
    if (JSON.stringify(tl78(mergeKLists([fl78([1,4,7]),fl78([2,5,8]),fl78([3,6,9])]))) !==
        JSON.stringify([1,2,3,4,5,6,7,8,9]))
        throw new Error("assertion failed");
    console.log("All Tests Passed");
}
