use std::collections::HashMap;

pub fn find_itinerary(flights: &[(&str, &str)], start: &str) -> Option<Vec<String>> {
    let mut graph: HashMap<&str, Vec<&str>> = HashMap::new();
    for &(src, dst) in flights {
        graph.entry(src).or_default().push(dst);
    }
    for dsts in graph.values_mut() { dsts.sort(); }

    let mut result: Vec<String> = Vec::new();
    fn dfs<'a>(airport: &'a str, graph: &mut HashMap<&'a str, Vec<&'a str>>, result: &mut Vec<String>) {
        while let Some(dsts) = graph.get_mut(airport) {
            if dsts.is_empty() { break; }
            let next = dsts.remove(0);
            dfs(next, graph, result);
        }
        result.insert(0, airport.to_string());
    }
    dfs(start, &mut graph, &mut result);
    if result.len() == flights.len() + 1 { Some(result) } else { None }
}

pub fn problem41() {
    println!("Problem 41:");
    let f1 = vec![("SFO","HKO"),("YYZ","SFO"),("YUL","YYZ"),("HKO","ORD")];
    assert_eq!(find_itinerary(&f1,"YUL").unwrap(),
        vec!["YUL","YYZ","SFO","HKO","ORD"]);

    let f2 = vec![("SFO","COM"),("COM","YYZ")];
    assert!(find_itinerary(&f2,"COM").is_none());

    let f3 = vec![("A","B"),("A","C"),("B","C"),("C","A")];
    assert_eq!(find_itinerary(&f3,"A").unwrap(),
        vec!["A","B","C","A","C"]);
    println!("All Tests Passed");
}
