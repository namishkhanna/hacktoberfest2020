import _ from 'lodash';

function search(target, data) {
  const filtered = [];

  _.forEach(data, value => {
    const flatMap = _.toArray(value);
    const stringMap = flatMap.toString();

    if (stringMap.toLowerCase().includes(target.toLowerCase()) && target !== '') {
      filtered.push(value);
    }
  });

  return target === '' ? data : filtered;
};

export default search;
