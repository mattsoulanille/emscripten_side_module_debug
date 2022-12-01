import * as Comlink from 'comlink';


const worker = new Worker('/dist/worker.js');
const {run} = Comlink.wrap(worker);

run();
